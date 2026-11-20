#pragma once
#include <Windows.h>


class InputManager
{
public:

	InputManager();

	bool gamepadActive = true;
	bool anyPadConnected = false;

	float dpadDeadzone = 0.1f; // Deadzone for dpad
	float leftStickDeadZone = 0.1f; // Deadzone for left thumbstick
	float rightStickDeadZone = 0.1f; // Deadzone for right thumbstick
	float leftTriggerDeadzone = 0.05f; // Deadzone for left trigger
	float rightTriggerDeadzone = 0.05f; // Deadzone for right trigger

	float leftStickSensitivity = 1.0f;
	float rightStickSensitivity = 1.0f;

	void Update();
	void Vibrate(float leftMotorSpeed,
				float rightMotorSpeed,
				float leftTriggerMotorSpeed,
				float rightTriggerMotorSpeed,
				float duration);

	void setGamepadUsage(bool useGamepad);
	void updateTriggers();
	void updateKeyboard();



	const int aButton = 0;
	const int bButton = 1;
	const int xButton = 2;
	const int yButton = 3;
	const int leftBumper = 4;
	const int rightBumper = 5;
	const int viewButton = 6;
	const int menuButton = 7;
	const int leftStickButton = 8;
	const int rightStickButton = 9;


	const int axisLeftStickX = 0;
	const int axisLeftStickY = 1;
	const int axisRightStickX = 2;
	const int axisRightStickY = 3;


	bool aPressed = false;
	bool bPressed = false;
	bool xPressed = false;
	bool yPressed = false;
	bool leftBumperPressed = false;
	bool rightBumperPressed = false;
	bool viewPressed = false;
	bool menuPressed = false;
	bool leftStickPressed = false;
	bool rightStickPressed = false;
	bool leftTriggerPressed = false;
	bool rightTriggerPressed = false;
	bool dpadLeftPressed = false;
	bool dpadRightPressed = false;
	bool dpadUpPressed = false;
	bool dpadDownPressed = false;

	float leftStickValueX = 0;
	float leftStickValueY = 0;
	float rightStickValueX = 0;
	float rightStickValueY = 0;

	float leftTriggerValue = 0;
	float rightTriggerValue = 0;
	float leftMotorValue = 0;
	float rightMotorValue = 0;

	bool qKeyPressed = false;
	bool wKeyPressed = false;
	bool eKeyPressed = false;
	bool rKeyPressed = false;
	bool tKeyPressed = false;
	bool yKeyPressed = false;
	bool uKeyPressed = false;
	bool iKeyPressed = false;
	bool oKeyPressed = false;
	bool pKeyPressed = false;
	bool aKeyPressed = false;
	bool sKeyPressed = false;
	bool dKeyPressed = false;
	bool fKeyPressed = false;
	bool gKeyPressed = false;
	bool hKeyPressed = false;
	bool jKeyPressed = false;
	bool kKeyPressed = false;
	bool lKeyPressed = false;
	bool zKeyPressed = false;
	bool xKeyPressed = false;
	bool cKeyPressed = false;
	bool vKeyPressed = false;
	bool bKeyPressed = false;
	bool nKeyPressed = false;
	bool mKeyPressed = false;
	bool escapeKeyPressed = false;
	bool enterKeyPressed = false;
	bool spaceKeyPressed = false;
	bool shiftKeyPressed = false;
	bool controlKeyPressed = false;
	bool altKeyPressed = false;
	bool tabKeyPressed = false;
	bool backspaceKeyPressed = false;
	bool leftArrowKeyPressed = false;
	bool rightArrowKeyPressed = false;
	bool upArrowKeyPressed = false;
	bool downArrowKeyPressed = false;
	bool num1Pressed = false;
	bool num2Pressed = false;
	bool num3Pressed = false;
	bool num4Pressed = false;
	bool num5Pressed = false;
	bool num6Pressed = false;
	bool num7Pressed = false;
	bool num8Pressed = false;
	bool num9Pressed = false;
	bool num0Pressed = false;
	bool f1KeyPressed = false;
	bool f2KeyPressed = false;
	bool f3KeyPressed = false;
	bool f4KeyPressed = false;
	bool f5KeyPressed = false;
	bool f6KeyPressed = false;
	bool f7KeyPressed = false;
	bool f8KeyPressed = false;
	bool f9KeyPressed = false;
	bool f10KeyPressed = false;
	bool f11KeyPressed = false;


};

