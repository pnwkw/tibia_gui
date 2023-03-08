#ifndef GUI_CORE
#define GUI_CORE

#include <windows.h>

class GUIcore
{
public:
  void *GUIbckgStruct;
  int type;
  GUIcore *parentWindow;
  GUIcore *nextItem;
  int left_offset;
  int top_offset;
  int width;
  int height;
  GUIcore *firstChild;
  GUIcore *childWindowClicked;

  void _cdecl RegisterChild(GUIcore *child);
  void _cdecl ShowChild(GUIcore *child, DWORD x, DWORD y, DWORD width, DWORD height);
  void _cdecl SetChildPos(GUIcore *child, int x, int y);

  virtual int unk0();
  virtual void onGUIItemCreate(void *item, int u);
  virtual int unk1();
  virtual int unk2();
  virtual int unk3();
  virtual int unk4();
  virtual int unk5();
  virtual int unk6();
  virtual int unk7();
  virtual int unk8();
  virtual int unk9();
  virtual int unk10();
  virtual int unk11();
  virtual int onWindowResize(int width, int height);
  virtual int unk12();
  virtual int unk13();
  virtual int unk14();
  virtual int onDraw(int surface, int x, int y);
  virtual void onGUIResize();
  virtual void onMouseMove(int mouseX, int mouseY);
  virtual void onLeftMouseUp(int mouseX, int mouseY);
  virtual void onLeftMouseDblClick(int mouseX, int mouseY);
  virtual int unk15();
  virtual void onRightMouseUp(int mouseX, int mouseY);
  virtual GUIcore *getChild();
  virtual int unk16();
  virtual int unk17();
  virtual void onKeyDown(int charID);
  virtual void guiItemFireEvent(int eventID);
};

#endif
