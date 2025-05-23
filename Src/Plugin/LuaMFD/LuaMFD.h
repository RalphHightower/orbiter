// Copyright (c) Martin Schweiger
// Licensed under the MIT License

#ifndef __LUAMFD_H
#define __LUAMFD_H

#include "MfdInterpreter.h"

// ==============================================================
// MFD class interface

class ScriptMFD: public MFD2 {
public:
	ScriptMFD (DWORD w, DWORD h, VESSEL *vessel);
	~ScriptMFD();
	char *ButtonLabel (int bt) override;
	int ButtonMenu (const MFDBUTTONMENU **menu) const;
	bool ConsumeKeyBuffered (DWORD key) override;
	bool ConsumeButton (int bt, int event) override;
	bool Update (oapi::Sketchpad *skp) override;
	bool Input (const char *line);
	void QueryCommand ();
	void CreateInterpreter ();
	void DeleteInterpreter ();
	void SetPage (DWORD newpg);
	static bool ScriptInput (void *id, char *str, void *data);
	static OAPI_MSGTYPE MsgProc (UINT msg, UINT mfd, WPARAM wparam, LPARAM lparam);

protected:
	void SetFontSize (double size);

private:
	InterpreterList::VesselInterp *vi;
	OBJHANDLE hVessel;      // vessel object handle
	HANDLE interpTh;        // interpreter thread handle
	oapi::Font *hFont;      // font handle
	DWORD pg;               // current page   
	DWORD fw, fh;           // character width, height
	DWORD nchar;            // characters per line displayed
	DWORD nline;            // max number of lines displayed
};

#endif // !__LUAMFD_H