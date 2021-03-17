#include <windows.h>
#include <stdio.h>

#define APP_SAVE 9000
#define WM_EMAIL 101
#define WM_MESSAGE 102
#define WM_RESTART 103
#define WM_INFO 104

LRESULT CALLBACK WndProc(); 

int text_cursor = 0;
char alpha[27] = "abcdefghijklmnopqrstuvwxyz"; 
char letter;

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {

    FILE* text_cursor_file = fopen("text_cursor.txt", "r"); 
    if(text_cursor_file) {
        fscanf(text_cursor_file, "%d", &text_cursor); 
    }
    printf("You are at position %d\n", text_cursor); 
    fclose(text_cursor_file); 

    char const*const window_class_name = "sample_window_class"; 

    WNDCLASSEX window_class; 
    
    window_class.cbSize = sizeof(WNDCLASSEX); 
    window_class.cbClsExtra = 0; 
    window_class.cbWndExtra = 0; 

    window_class.style = CS_VREDRAW | CS_HREDRAW; 
    
    window_class.lpfnWndProc = WndProc; 
    window_class.lpszClassName = window_class_name; 
    
    window_class.hInstance = hInstance;
    window_class.hbrBackground = (HBRUSH)(COLOR_WINDOW); 
    window_class.hCursor = LoadCursor(NULL, IDC_CROSS); 
    window_class.hIcon = LoadIcon(NULL, IDI_APPLICATION); 
    window_class.hIconSm = LoadIcon(NULL, IDI_APPLICATION); 

    if(!RegisterClassEx(&window_class)) {
        fprintf(stderr, "Error registering window class.\n"); 
        return EXIT_FAILURE; 
    }

    int window_x = GetSystemMetrics(SM_CXSCREEN); 
    int window_y = GetSystemMetrics(SM_CYSCREEN); 
    printf("window size: %d\n", window_x); 

    HWND hwnd = CreateWindowEx(
        0, 
        window_class_name, 
        "Text App", 
        WS_OVERLAPPEDWINDOW, 
        window_x - 500, 
        window_y - 500, 
        500, 
        500, 
        NULL, 
        NULL, 
        hInstance, 
        NULL
    ); 
    if(!hwnd) {
        fprintf(stderr, "Error creating window.\n"); 
        return EXIT_FAILURE; 
    }
    // ShowWindow(hwnd, SW_HIDE); 
    ShowWindow(hwnd, nCmdShow); 
    UpdateWindow(hwnd); 

    MSG message; 
    while(0 < GetMessage(&message, NULL, 0, 0)) {
        TranslateMessage(&message); 
        DispatchMessage(&message); 
    }
    
    
    return 0; 
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
    switch(msg) {
        case WM_CREATE: {
            HMENU menu, sub_menu; 
            
            menu = CreateMenu(); 
            sub_menu = CreatePopupMenu(); 

            AppendMenu(sub_menu, MF_STRING, (UINT)APP_SAVE, "&Save"); 
            AppendMenu(sub_menu, MF_STRING, (UINT)WM_DESTROY, "&Exit"); 
            AppendMenu(menu, MF_STRING | MF_POPUP, (UINT)sub_menu, "&File"); 
            sub_menu = CreatePopupMenu();
            AppendMenu(sub_menu, MF_STRING, (UINT)WM_EMAIL,"&Email"); 
            AppendMenu(sub_menu, MF_STRING, (UINT)WM_MESSAGE,"&Message");
            AppendMenu(menu, MF_STRING | MF_POPUP, (UINT)sub_menu, "&Share");
            sub_menu = CreatePopupMenu();
            AppendMenu(sub_menu, MF_STRING, (UINT)WM_UNDO,"&Undo");
            AppendMenu(sub_menu, MF_STRING, (UINT)WM_RESTART, "&Restart"); 
            AppendMenu(menu, MF_STRING | MF_POPUP, (UINT)sub_menu, "&Edit");
            sub_menu = CreatePopupMenu();
            AppendMenu(sub_menu, MF_STRING, (UINT)WM_INFO, "&Info"); 
            AppendMenu(menu, MF_STRING | MF_POPUP, (UINT)sub_menu, "&Help");

            SetMenu(hwnd, menu); 

            break; 
        }
        case WM_COMMAND: 
            switch(LOWORD(wParam)) {
                case APP_SAVE: {
                    FILE* text_cursor_file = fopen("text_cursor.txt", "w"); 
                    fprintf(text_cursor_file, "%d", text_cursor); 
                    fflush(text_cursor_file); 
                    fclose(text_cursor_file); 
                    MessageBox(hwnd, "File saved", "Information", MB_OKCANCEL | MB_APPLMODAL); 
                    break; 
                }
                case WM_EMAIL: {
                    MessageBox(hwnd, "Text shared through email", "Information", MB_OKCANCEL);
                    //copy text into an email for the user to send
                    break;
                }
                case WM_MESSAGE:{
                    MessageBox(hwnd, "Text shared through messenger app", "Information", MB_OKCANCEL);
                    //copy text into a message for the user to send
                    break;
                }
                case WM_UNDO:{
                     MessageBox(hwnd, "Are you sure you want to undo?", "Warning", MB_OKCANCEL);
                     //undo what the user just typed
                     break;
                }
                case WM_RESTART:{
                    MessageBox(hwnd, "Are you sure you want to restart this text app?", "Warning", MB_OKCANCEL);
                    //restart
                    break;
                }
                case WM_INFO:{
                    MessageBox(hwnd, "A text app that checks if you can type the alphabet without any errors", "Help", MB_OKCANCEL);
                    break;
                }
                case WM_DESTROY: 
                    PostQuitMessage(0); 
                    break; 
            }
            break; 
        case WM_CHAR: {
            printf("%c", wParam); 
            if(wParam == 's') {
                text_cursor++; 
                printf(" was correct, you are now at position %d", text_cursor); 
            }
            printf("\n"); 
            InvalidateRect(hwnd, NULL, TRUE); 
            break; 
        }
        case WM_PAINT: {
            InvalidateRect(hwnd, NULL, TRUE); 
            PAINTSTRUCT ps; 
            HDC hdc = BeginPaint(hwnd, &ps); 

            char buffer[1024] = {0}; 
            sprintf(buffer, "bcdefghijklmnopqrstuvwxyz"); //I could not figure out how to make the buffer user input
                                                           //and to have that updated as it printed into the window
            TextOut(hdc, 50, 50, "Type the alphabet:", 19);
            TextOut(hdc, 50, 25, alpha, strlen(alpha)); 

            //checks user input and alpha array values match and return feedback
            for(int i = 0; i <= 27; i++){
                //buffer[i] += letter;
                if(buffer[i] == alpha[i]){
                    TextOut(hdc, 50, 75, buffer, strlen(buffer));
                }
                else{
                    TextOut(hdc, 50, 75, buffer, strlen(buffer));
                    TextOut(hdc, 50, 100, "You have made an error, game over.", 35);
                    break;
                }
            }

            /*int check = 1;
            //Final check to make sure arrays match
            for(int i = 0; i <= 27; i++){
                if(buffer[i] =! alpha [i]){
                    check = 0;
                }
            }

            if(check == 1){
                TextOut(hdc, 50, 150, "You typed it correctly, gongrats!", 34);
            }
            if(check == 0){
                TextOut(hdc, 50, 150, "The text does not match, try again.", 36);
            }*/



            EndPaint(hwnd, &ps); 
            break; 
        }
        case WM_CLOSE: {
            DestroyWindow(hwnd); 
            break; 
        }
        case WM_DESTROY: 
            PostQuitMessage(0); 
            break; 
        default: 
            return DefWindowProc(hwnd, msg, wParam, lParam); 
    }
    return 0; 
}
