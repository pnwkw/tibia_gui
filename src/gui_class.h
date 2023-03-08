#ifndef GUI_CLASSES
#define GUI_CLASSES

#include "gui_core.h"

class GUIContainerWindow : public GUIcore
{
public:
    int relative_left_offset;
    int relative_top_offset;
    int width2;
    int height2;
    GUIcore *currentlyMovedWindow;
    int unk;
    int height_pixels;
};

class GUIGameWindow : public GUIcore
{
public:
    GUIcore *worldWindow;
    int top_margin_size;
    int left_margin_size;
    int game_window_width;
    int game_window_height;
};

class GUIEquipmentWindow : public GUIcore
{
public:
    int unk;
    int top_left_margin_imageID;
    int top_margin_imageID;
    int top_right_imageID;
    int left_margin_imageID;
    int right_margin_imageID;
    int bottom_left_margin_imageID;
    int bottom_margin_imageID;
    int bottom_right_imageID;
    int unk2;
    int unk3;
    int helper_width;
    int helper_height;
};

class GUIMainWindow : public GUIcore
{
public:
    int unk;
    GUIGameWindow *gameWindow;
    GUIcore *playerWindow;
    GUIContainerWindow *containersWindow;
    GUIcore *firstChildPlayerWindow;
    GUIcore *chatWindow;
    GUIcore *resizeBarWindow;
};

// Useable classes

class GUIEditBox : public GUIcore
{
public:
    char *text;
    int size;
    int unk[13];
    short unk2;
    short current_position;

    GUIEditBox(DWORD max_len, DWORD start_len);
};

class GUINameBox : public GUIcore // 0x4C
{
public:
    int unk3[8];

    GUINameBox(int font, int nRed, int nBlue, int nGreen, int algin, char *name);
};

class GUIIconBox : public GUIcore // 0x28
{
public:
    GUIIconBox(int icon);
};

class GUIContainerBox : public GUIcore // 0x70
{
public:
    int unk3[18];

    void RegisterCloseButton(GUIcore *child);
    void RegisterMinimiseButton(GUIcore *child);
    void RegisterIcon(GUIcore *child);
    void RegisterNamePlate(GUIcore *child);

    GUIContainerBox(int identifier, GUIcore *body, int resizeable, int arg4);
};

class GUIContainerBody : public GUIcore
{
public:
    int unk[5];
};

class GUICheckBox : public GUIcore
{
public:
    int unk;
    GUIcore *child;
    char isTicked;
    char unk2;
    short unk3;
    int unk4;
    int unk5;

    GUICheckBox(char *label, GUIcore *EventReciver, int arg3);
};

class GUIMiniButtonBox : public GUIcore // 0x48
{
public:
    int unk3[7];

    GUIMiniButtonBox(int unk1, int unk2, int image_notclicked, int image_clicked, GUIcore *EventReciver, int eventID, char *description, int unk8);
};

class GUISkillBody : public GUIContainerBody
{
public:
    int unk3[4];

    GUISkillBody();
};

class GUIButtonBox : public GUIcore
{
public:
    int unk3[21];

    GUIButtonBox(int arg1, int arg2, char *label, int arg3, int arg4, GUIcore *EventReciver, int eventID, char *description);
};

class GUIBody : public GUIcore
{
public:
    int unk3[12];

    GUIBody();
    void Unk();
    GUIBody(int arg1, int arg2);
};

class GUIScroller : public GUIcore
{
public:
    int unk3[4];

    GUIScroller(int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7, int arg8, int arg9);
};

class GUIEvent : public GUIcore
{
public:
    bool clicked;

    GUIEvent();
    virtual void guiItemFireEvent(int eventID);
};

#endif
