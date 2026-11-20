#include "InputManager.h"
#include <iostream>

 // X-Box Controller input manager
//  Add in Keyboard handling

//InputManager::InputManager()
//{
//	HRESULT hr = GameInputCreate(gameInput.GetAddressOf());
//	if (FAILED(hr) || !gameInput)
//	{
//		std::cerr << "Failed to initialize GameInput.\n";
//	}
//
//}
//
//void InputManager::setGamepadUsage(bool useGamepad)
//{
//	if (useGamepad == true)
//	{
//		gamepadActive = true;
//	}
//	else
//	{
//		gamepadActive = false;
//	}
//}

//void InputManager::Update()
//{
//	if (gamepadActive)
//	{
//		float dpadX = sf::Joystick::getAxisPosition(0, sf::Joystick::Axis::PovX);
//		float dpadY = sf::Joystick::getAxisPosition(0, sf::Joystick::Axis::PovY);
//
//
//		if (sf::Joystick::isButtonPressed(0, aButton))
//		{
//			aPressed = true;
//		}
//		else
//		{
//			aPressed = false;
//		}
//
//		if (sf::Joystick::isButtonPressed(0, bButton))
//		{
//			bPressed = true;
//		}
//		else
//		{
//			bPressed = false;
//		}
//
//		if (sf::Joystick::isButtonPressed(0, xButton))
//		{
//			xPressed = true;
//		}
//		else
//		{
//			xPressed = false;
//		}
//
//		if (sf::Joystick::isButtonPressed(0, yButton))
//		{
//			yPressed = true;
//		}
//		else
//		{
//			yPressed = false;
//		}
//
//		if (sf::Joystick::isButtonPressed(0, leftBumper))
//		{
//			leftBumperPressed = true;
//		}
//		else
//		{
//			leftBumperPressed = false;
//		}
//
//		if (sf::Joystick::isButtonPressed(0, rightBumper))
//		{
//			rightBumperPressed = true;
//		}
//		else
//		{
//			rightBumperPressed = false;
//		}
//
//		if (sf::Joystick::isButtonPressed(0, viewButton))
//		{
//			viewPressed = true;
//		}
//		else
//		{
//			viewPressed = false;
//		}
//
//		if (sf::Joystick::isButtonPressed(0, menuButton))
//		{
//			menuPressed = true;
//		}
//		else
//		{
//			menuPressed = false;
//		}
//
//		if (sf::Joystick::isButtonPressed(0, leftStickButton))
//		{
//			leftStickPressed = true;
//		}
//		else
//		{
//			leftStickPressed = false;
//		}
//
//		if (sf::Joystick::isButtonPressed(0, rightStickButton))
//		{
//			rightStickPressed = true;
//		}
//		else
//		{
//			rightStickPressed = false;
//		}
//
//		if (dpadX < -dpadDeadzone)
//		{
//			dpadLeftPressed = true;
//		}
//		else
//		{
//			dpadLeftPressed = false;
//		}
//
//		if (dpadX > dpadDeadzone)
//		{
//			dpadRightPressed = true;
//		}
//		else
//		{
//			dpadRightPressed = false;
//		}
//
//		if (dpadY > dpadDeadzone)
//		{
//			dpadUpPressed = true;
//		}
//		else
//		{
//			dpadUpPressed = false;
//		}
//
//		if (dpadY < -dpadDeadzone)
//		{
//			dpadDownPressed = true;
//		}
//		else
//		{
//			dpadDownPressed = false;
//		}
//
//		if (std::abs(sf::Joystick::getAxisPosition(0, sf::Joystick::Axis::X)) > leftStickDeadZone * 100)
//		{
//			leftStickValueX = (sf::Joystick::getAxisPosition(0, sf::Joystick::Axis::X) / 100) * leftStickSensitivity;
//		}
//		else
//		{
//			leftStickValueX = 0;
//		}
//
//		if (std::abs(sf::Joystick::getAxisPosition(0, sf::Joystick::Axis::Y)) > leftStickDeadZone * 100)
//		{
//			leftStickValueY = (sf::Joystick::getAxisPosition(0, sf::Joystick::Axis::Y) / 100) * leftStickSensitivity;
//		}
//		else
//		{
//			leftStickValueY = 0;
//		}
//
//		if (std::abs(sf::Joystick::getAxisPosition(0, sf::Joystick::Axis::U)) > rightStickDeadZone * 100)
//		{
//			rightStickValueX = (sf::Joystick::getAxisPosition(0, sf::Joystick::Axis::U) / 100) * rightStickSensitivity;
//		}
//		else
//		{
//			rightStickValueX = 0;
//		}
//
//		if (std::abs(sf::Joystick::getAxisPosition(0, sf::Joystick::Axis::V)) > rightStickDeadZone * 100)
//		{
//			rightStickValueY = (sf::Joystick::getAxisPosition(0, sf::Joystick::Axis::V) / 100) * rightStickSensitivity * -1; // Invert Y axis back to up = positive
//		}
//		else
//		{
//			rightStickValueY = 0;
//		}
//
//		updateTriggers();
//
//		updateKeyboard();
//		
//
//	}
//
//}
//
//
//
//void InputManager::updateTriggers()
//{
//	XINPUT_STATE state;
//	DWORD result = XInputGetState(0, &state); //DWORD is an unasigned long (32-bit integer)
//
//	anyPadConnected = false;
//
//	for (DWORD i = 0; i < 4; i++)
//	{
//		XINPUT_STATE state;
//		if (XInputGetState(i, &state) == ERROR_SUCCESS)
//		{
//			// Trigger values
//			BYTE leftTrigger = state.Gamepad.bLeftTrigger;
//			BYTE rightTrigger = state.Gamepad.bRightTrigger;
//
//
//			// Left trigger check
//			if (leftTrigger > (leftTriggerDeadzone * 255)) // Scale deadzone (0.0 to 1.0) to byte range (0 to 255)
//			{
//				leftTriggerPressed = true;
//				leftTriggerValue = static_cast<float>(leftTrigger) / 255;
//			}
//
//			else
//			{
//				leftTriggerPressed = false;
//				leftTriggerValue = 0;
//			}
//
//
//			// Right trigger check
//			if (rightTrigger > (rightTriggerDeadzone * 255)) // Scale deadzone (0.0 to 1.0) to byte range (0 to 255)
//			{
//				rightTriggerPressed = true;
//				rightTriggerValue = static_cast<float>(rightTrigger) / 255;
//			}
//			else
//			{
//				rightTriggerPressed = false;
//				rightTriggerValue = 0;
//			}
//			anyPadConnected = true;
//		}
//	}
//	if (!anyPadConnected)
//	{
//		setGamepadUsage(false);
//	}
//	else
//	{
//		setGamepadUsage(true);
//	}
//}
//
//
//
//void InputManager::updateKeyboard()
//{
//	qKeyPressed = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Q);
//	wKeyPressed = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W);
//	eKeyPressed = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::E);
//	rKeyPressed = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::R);
//	tKeyPressed = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::T);
//	yKeyPressed = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Y);
//	uKeyPressed = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::U);
//	iKeyPressed = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::I);
//	oKeyPressed = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::O);
//	pKeyPressed = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::P);
//	aKeyPressed = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A);
//	sKeyPressed = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S);
//	dKeyPressed = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D);
//	fKeyPressed = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::F);
//	gKeyPressed = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::G);
//	hKeyPressed = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::H);
//	jKeyPressed = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::J);
//	kKeyPressed = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::K);
//	lKeyPressed = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::L);
//	zKeyPressed = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Z);
//	xKeyPressed = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::X);
//	cKeyPressed = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::C);
//	vKeyPressed = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::V);
//	bKeyPressed = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::B);
//	nKeyPressed = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::N);
//	mKeyPressed = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::M);
//
//
//	escapeKeyPressed = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape);
//	enterKeyPressed = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Enter);
//	spaceKeyPressed = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space);
//	shiftKeyPressed = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::LShift) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::RShift);
//	controlKeyPressed = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::LControl) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::RControl);
//	altKeyPressed = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::LAlt) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::RAlt);
//	tabKeyPressed = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Tab);
//	backspaceKeyPressed = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Backspace);
//
//	leftArrowKeyPressed = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left);
//	rightArrowKeyPressed = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right);
//	upArrowKeyPressed = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up);
//	downArrowKeyPressed = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down);
//
//	num1Pressed = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Num1);
//	num2Pressed = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Num2);
//	num3Pressed = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Num3);
//	num4Pressed = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Num4);
//	num5Pressed = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Num5);
//	num6Pressed = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Num6);
//	num7Pressed = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Num7);
//	num8Pressed = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Num8);
//	num9Pressed = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Num9);
//	num0Pressed = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Num0);
//
//	f1KeyPressed = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::F1);
//	f2KeyPressed = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::F2);
//	f3KeyPressed = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::F3);
//	f4KeyPressed = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::F4);
//	f5KeyPressed = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::F5);
//	f6KeyPressed = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::F6);
//	f7KeyPressed = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::F7);
//	f8KeyPressed = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::F8);
//	f9KeyPressed = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::F9);
//	f10KeyPressed = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::F10);
//	f11KeyPressed = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::F11);
//}
//
//
//
//
//void InputManager::Vibrate(	float leftMotorSpeed,
//							float rightMotorSpeed,
//							float leftTriggerMotorSpeed,
//							float rightTriggerMotorSpeed,
//							float duration)
//{
//
//	if (!gameInput) return;
//
//
//	HRESULT hr = gameInput->GetCurrentReading(GameInputKindGamepad, nullptr, reading.GetAddressOf());
//
//	if (FAILED(hr) || !reading) return;
//
//	Microsoft::WRL::ComPtr<IGameInputDevice> device;
//	reading->GetDevice(device.GetAddressOf());
//
//	if (!device) return;
//	
//	GameInputRumbleParams rumble = {};
//	rumble.lowFrequency = leftMotorSpeed;			   // left rumble motor
//	rumble.highFrequency = rightMotorSpeed;		      // right rumble motor
//	rumble.leftTrigger = leftTriggerMotorSpeed;      // left trigger motor
//	rumble.rightTrigger = rightTriggerMotorSpeed;   // right trigger motor
//
//	device->SetRumbleState(&rumble);
//	
//
//}











































