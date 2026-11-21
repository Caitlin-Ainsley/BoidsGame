#pragma once

#include "Input.h"

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//	Classname	: InputManager
//	Author		: Caitlin Bruce
//	Date		: 20/11/2026
//	Description : This class is the manager I have made to wrap the mouse and keyboard input handling
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class InputManager
{
public:

	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//	Variables
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// RI_MOUSE_WHEEL = scroll wheel	MOUSE_MOVE_RELATIVE = movement data relative to last mouse position

	bool qKey = false;	bool num1	 = false;		  bool f1Key  = false;			   bool leftMouseButton   = false;
	bool wKey = false;	bool num2	 = false;		  bool f2Key  = false;			   bool rightMouseButton  = false;
	bool eKey = false;	bool num3	 = false;		  bool f3Key  = false;			   bool middleMouseButton = false;
	bool rKey = false;	bool num4	 = false;		  bool f4Key  = false;			   bool x1MouseButton	  = false;
	bool tKey = false;	bool num5	 = false;		  bool f5Key  = false;			   bool x2MouseButton     = false;
	bool yKey = false;	bool num6	 = false;		  bool f6Key  = false;			   
	bool uKey = false;	bool num7	 = false;		  bool f7Key  = false;			   bool backspaceKey = false;
	bool iKey = false;	bool num8	 = false;		  bool f8Key  = false;			   bool capsKey	     = false;
	bool oKey = false;	bool num9	 = false;		  bool f9Key  = false;			   bool spaceKey	 = false;
	bool pKey = false;	bool num0	 = false;		  bool f10Key = false;			   bool enterKey	 = false;
	bool aKey = false;								  bool f11Key = false;			   bool escapeKey	 = false;
	bool sKey = false;	bool numpad1 = false;		  bool f12Key = false;			   bool tabKey		 = false;
	bool dKey = false;	bool numpad2 = false;		  
	bool fKey = false;	bool numpad3 = false;		  bool leftAltKey	   = false;
	bool gKey = false;	bool numpad4 = false;		  bool rightAltKey	   = false;
	bool hKey = false;	bool numpad5 = false;		  bool leftControlKey  = false;
	bool jKey = false;	bool numpad6 = false;		  bool rightControlKey = false;
	bool kKey = false;	bool numpad7 = false;		  bool leftShiftKey	   = false;
	bool lKey = false;	bool numpad8 = false;		  bool rightShiftKey   = false;
	bool zKey = false;	bool numpad9 = false;		  bool leftWindowsKey  = false;
	bool xKey = false;	bool numpad0 = false;		  bool rightWindowsKey = false;
	bool cKey = false;	
	bool vKey = false;	bool downArrowKey  = false;	  bool muteKey		   = false;
	bool bKey = false;	bool upArrowKey	   = false;   bool volumeUpKey	   = false;
	bool nKey = false;	bool rightArrowKey = false;   bool volumeDownKey   = false;
	bool mKey = false;	bool leftArrowKey  = false;	  

	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//	Constructors / Destructor
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	InputManager();  // Default constructor
	~InputManager(); // Default destructor

	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//	Member Functions
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	void Update();	 // Calls update on the keyboard and mouse
private:
	void UpdateKeyboard(); // Updates all of the keyboard boolean values
	void UpdateMouse();	   // Updates the mouse button boolean values, as well as the mouse's raw input data for movement and scroll wheel
};


