#include <raylib.h>
#include <chrono>
#include <ctime>

int screenHeight = GetScreenHeight();
int screenWidth = GetScreenWidth();
int windowHeight = 100;
int windowWidth = 500;
Vector2 mousePos;
int radius = 0;

std::time_t currentTime;

int main (int argc, char *argv[]) {
	InitWindow(screenWidth, screenHeight, "clock");
	SetTargetFPS(30);
	ToggleFullscreen();
	while (!WindowShouldClose()) {
		auto now = std::chrono::system_clock::now();
		currentTime = std::chrono::system_clock::to_time_t(now);
		//std::cout << currentTime << "\n";

		if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
			radius = 0;
			mousePos = GetMousePosition();
		}

		if(IsMouseButtonPressed(MOUSE_BUTTON_MIDDLE)){
			ToggleFullscreen();
			SetWindowSize(windowWidth, windowHeight);
		}

		BeginDrawing();
		ClearBackground(BLACK);
		DrawText(std::ctime(&currentTime), 0, 0, 40, RAYWHITE);
		DrawText("left click - ripple", 0, 60, 10, DARKGRAY);
		DrawText("middle click - smol display", 0, 70, 10, DARKGRAY);
		radius +=	2 ;
		DrawCircleLines(mousePos.x, mousePos.y, radius, BLUE);

		EndDrawing();
	}
	return 0;
}
