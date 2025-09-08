#include <windows.h>
#include <string>
#include <map>
#include <vector>
#include <cmath>
#include <stdlib.h>
#include <time.h>


#define WINDOW_WIDTH 1920/4*3
#define WINDOW_HEIGHT 1080/4*3
#define TIMER_ID 1 // Timer ID for the 60 FPS redraw

// Define background color (RGB)
struct {
    int r, g, b;
} bgColor = { 50, 50, 50 }; // Set background color to RGB(50, 50, 50)


int rand_in_range(int min, int max) {
    return min + rand() % (max - min + 1);
}

class Circle {
public:
    int x, y, radius;
    bool alive;
    COLORREF color; // Add a color property to the circle
    
    // Constructor that takes color as a parameter
    Circle(int centerX, int centerY, int r, COLORREF circleColor = RGB(255, 255, 255)) 
        : x(centerX), y(centerY), radius(r), alive(true), color(circleColor) {}

    // Method to draw the circle with the specified color
    void Draw(HDC hdc) {
        if (alive) {
            // Create a solid brush with the circle's color
            HBRUSH hBrush = CreateSolidBrush(color);
            
            // Fill the circle using the brush
            SelectObject(hdc, hBrush);
            Ellipse(hdc, x - radius, y - radius, x + radius, y + radius);

            // Clean up the brush
            DeleteObject(hBrush);
        }
    }

    bool OverlapsWith(int otherX, int otherY, int otherRadius) const {
        int dx = otherX - this->x;
        int dy = otherY - this->y;
        double distance = sqrt(pow(dx, 2) + pow(dy, 2));
        return distance <= (radius + otherRadius);
    }

    void Move(int dx, int dy) {
        if (alive) {
            x += dx;
            y += dy;
            if (x > WINDOW_WIDTH) x = 0;
            if (x < 0) x = WINDOW_WIDTH;
            if (y > WINDOW_HEIGHT) y = 0;
            if (y < 0) y = WINDOW_HEIGHT;
        }
    }
};


class Bullet {
public :
    int x, y, radius, speed_x, speed_y;
    

    Bullet(int centerX, int centerY, int r, int speed_x, int speed_y) : x(centerX), y(centerY), radius(r), speed_x(speed_x), speed_y(speed_y) {}

    void Draw(HDC hdc) {
        Ellipse(hdc, x - radius, y - radius, x + radius, y + radius);
    }

    void update() {
        x -= speed_x;
        y -= speed_y;
    }

    bool OverlapsWith(int otherX, int otherY, int otherRadius) const {
        // Calculate the distance between the centers
        int dx = otherX - this->x;
        int dy = otherY - this->y;
        double distance = sqrt(pow(dx, 2) + pow(dy, 2));  // Pzthagorus ahh moment

        // Check if the distance between centers is less than or equal to the sum of the radii
        return distance <= (radius + otherRadius);
    }
};

class Enemy {
public:
    int x, y, radius;
    int speed = 5;
    COLORREF color; // Add a color property to the circle
    // Constructor
    Enemy(int centerX, int centerY, int r, COLORREF circleColor) : x(centerX), y(centerY), radius(r), color(circleColor) {}


    // Method to draw the circle
        void Draw(HDC hdc) {
            // Create a solid brush with the circle's color
            HBRUSH hBrush = CreateSolidBrush(color);
            
            // Fill the circle using the brush
            SelectObject(hdc, hBrush);
            Ellipse(hdc, x - radius, y - radius, x + radius, y + radius);

            // Clean up the brush
            DeleteObject(hBrush);
    }

    // Method to move the enemy
    void Update(int playerX, int playerY) {
        if (playerX < x) {
            x -= speed;
        }
        else if (playerX > x) {
            x += speed;
        }
        if (playerY < y) {
            y -= speed;
        }
        else if (playerY > y) {
            y += speed;
        }
    }
};



std::vector<Enemy> Enemies; // <-- správná deklarace
std::vector<Bullet> bullets; // <-- správná deklarace

// Convert char* to LPCWSTR for Windows API functions
LPCWSTR CharToLPCWSTR(const char* str) {
    int length = MultiByteToWideChar(CP_ACP, 0, str, -1, NULL, 0);
    wchar_t* wideStr = (wchar_t*)malloc(length * sizeof(wchar_t));
    MultiByteToWideChar(CP_ACP, 0, str, -1, wideStr, length);
    return wideStr;
}
static Circle player(400, 300, 20, RGB(255,255,255));  // Create a Circle object at center with radius 100


// Call this periodically in your main loop or a timer callback
void HandleContinuousInput(HWND hwnd) {
    int moveDistance = 10;

    if (GetAsyncKeyState('W') & 0x8000) {
        player.Move(0, -moveDistance); // Move up
    }
    if (GetAsyncKeyState('S') & 0x8000) {
        player.Move(0, moveDistance); // Move down
    }
    if (GetAsyncKeyState('A') & 0x8000) {
        player.Move(-moveDistance, 0); // Move left
    }
    if (GetAsyncKeyState('D') & 0x8000) {
        player.Move(moveDistance, 0); // Move right
    }
    if (GetAsyncKeyState('B') & 0x8000) {
        Enemies.push_back(Enemy(rand_in_range(0, WINDOW_WIDTH), rand_in_range(0, WINDOW_HEIGHT), 20, RGB(255,0,0)));
    }
    InvalidateRect(hwnd, NULL, TRUE); // Trigger a redraw
}




// Window procedure function
LRESULT CALLBACK WindowProcedure(HWND hwnd, UINT msg, WPARAM wp, LPARAM lp) {
    

    switch (msg) {
    case WM_PAINT: {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hwnd, &ps);

        // Create a solid brush using bgColor
        HBRUSH hBrush = CreateSolidBrush(RGB(bgColor.r, bgColor.g, bgColor.b));

        // Fill the window background with the specified color
        FillRect(hdc, &ps.rcPaint, hBrush);

        // Draw the circle on top of the filled background
        player.Draw(hdc);

        // Draw Enemies
        for (size_t i = 0; i < Enemies.size(); ++i) {
            Enemies[i].Draw(hdc);
        }
        for (size_t i = 0; i < bullets.size(); ++i) {
            bullets[i].Draw(hdc);
        }

        

        // Clean up the brush
        DeleteObject(hBrush);

        EndPaint(hwnd, &ps);
        break;
    }
    case WM_TIMER: {
        // Redraw the window on each timer tick
        InvalidateRect(hwnd, NULL, TRUE); // Forces a repaint
        for (size_t i = 0; i < Enemies.size(); ++i) {
            Enemies[i].Update(player.x, player.y);
            if (player.OverlapsWith(Enemies[i].x, Enemies[i].y, Enemies[i].radius)) {
                printf_s("Overlap \n");
                player.alive = false;
            }
        }
        HandleContinuousInput(hwnd);

        for (size_t i = 0; i < bullets.size(); ++i) {
            bullets[i].update();
            for (size_t j = 0; j < Enemies.size(); ++j)
            if (bullets[i].OverlapsWith(Enemies[j].x, Enemies[j].y, Enemies[j].radius)) {
                Enemies.erase(Enemies.begin() + j);
            }
        }

        break;
    }
                 
    case WM_LBUTTONDOWN: {
        int mouse_x = LOWORD(lp);
        int mouse_y = HIWORD(lp);


        bullets.push_back(Bullet(player.x, player.y, 5, (player.x - mouse_x)/50, (player.y - mouse_y)/50));


        InvalidateRect(hwnd, NULL, TRUE); // Trigger redraw
        break;
    }

    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hwnd, msg, wp, lp);
    }
    return 0;
}





int main() {

    srand(time(NULL));
    // Initialize the window class
    const char* className = "CircleWindowClass";
    WNDCLASS wc = { 0 };
    wc.lpfnWndProc = WindowProcedure; // Set the window procedure
    wc.hInstance = GetModuleHandle(NULL);
    wc.lpszClassName = CharToLPCWSTR(className);
    Enemies.push_back(Enemy(0, 0, 20, RGB(255,0,0)));


    // Register the window class
    if (!RegisterClass(&wc)) {
        MessageBox(NULL, CharToLPCWSTR("Window class registration failed"), CharToLPCWSTR("Error"), MB_ICONERROR);
        return 1;
    }

    // Create the window
    HWND hwnd = CreateWindowEx(
        0,
        CharToLPCWSTR(className),
        CharToLPCWSTR("Circle Drawing"),
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, CW_USEDEFAULT, WINDOW_WIDTH, WINDOW_HEIGHT,
        NULL, NULL, wc.hInstance, NULL);

    if (hwnd == NULL) {
        MessageBox(NULL, CharToLPCWSTR("Window creation failed"), CharToLPCWSTR("Error"), MB_ICONERROR);
        return 1;
    }

    // Set the timer to call WM_TIMER every 1/60th of a second (16 ms)
    SetTimer(hwnd, TIMER_ID, 1000 / 60, NULL); // 1000 ms / 60 FPS = ~16 ms per tick

    // Show the window
    ShowWindow(hwnd, SW_SHOW);
    UpdateWindow(hwnd);
    

    // Message loop
    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0) > 0) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return 0;
}
