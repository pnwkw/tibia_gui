#ifndef STRUCTS
#define STRUCTS

typedef void _onGUIItemCreate(void *item, int u);
typedef int _onWindowResize(int width, int height);
typedef int _onDraw(int surface, int x, int y);
typedef void _onGUIResize();
typedef void _onMouseMove(int mouseX, int mouseY);
typedef void _onLeftMouseUp(int mouseX, int mouseY);
typedef void _onLeftMouseDblClick(int mouseX, int mouseY);
typedef void _onRightMouseUp(int mouseX, int mouseY);
typedef void _onKeyDown(int charID);
typedef void _playerWindowClick();

typedef struct GUICallback
{
    void *unk0;                                // 0x00
    _onGUIItemCreate *onGUIItemCreate;         // 0x04
    void *unk1;                                // 0x08
    void *unk2;                                // 0x0C
    void *unk3;                                // 0x10
    void *unk4;                                // 0x14
    void *unk5;                                // 0x18
    void *unk6;                                // 0x1C
    void *unk7;                                // 0x20
    void *unk8;                                // 0x24
    void *unk9;                                // 0x28
    void *unk10;                               // 0x2C
    void *unk11;                               // 0x30
    _onWindowResize *onWindowResize;           // 0x34
    void *unk12;                               // 0x38
    void *unk13;                               // 0x3C
    void *unk14;                               // 0x40
    _onDraw *onDraw;                           // 0x44
    _onGUIResize *onGUIResize;                 // 0x48
    _onMouseMove *onMouseMove;                 // 0x4C
    _onLeftMouseUp *onLeftMouseUp;             // 0x50
    _onLeftMouseDblClick *onLeftMouseDblClick; // 0x54
    void *unk15;                               // 0x58
    _onRightMouseUp *onRightMouseUp;           // 0x5C
    void *unk16;                               // 0x60 <- in chat class returning opened Chat, maybe getFocusedChild?
    void *unk17;                               // 0x64
    void *unk18;                               // 0x68
    _onKeyDown *onKeyDown;                     // 0x6C
    _playerWindowClick *playerWindowClick;     // 0x70
} /*__attribute__((packed))*/ GUICallback;

typedef struct Window
{
    GUICallback *callbacks;     // 0x00
    void *GUIbckgStruct;        // 0x04
    int type;                   // 0x08  0 - no background, 3 - used in resize bar, 8 - used in game window, 9 - has background
    Window *parentWindow;       // 0x0C
    Window *nextItem;           // 0x10
    int left_offset;            // 0x14
    int top_offset;             // 0x18
    int width;                  // 0x1C
    int height;                 // 0x20
    Window *firstChild;         // 0x24
    Window *childWindowClicked; // 0x28
} Window;

typedef struct ContainerWindow
{
    Window window;
    int relative_left_offset;     // 0x2C
    int relative_top_offset;      // 0x30
    int width2;                   // 0x34
    int height2;                  // 0x38
    Window *currentlyMovedWindow; // 0x3C
    int unk;                      // 0x40
    int height_pixels;            // 0x44
} ContainerWindow;

typedef struct EqMinimapWindow
{
    Window window;
    int unk;                        // 0x2C
    int top_left_margin_imageID;    // 0x30
    int top_margin_imageID;         // 0x34
    int top_right_imageID;          // 0x38
    int left_margin_imageID;        // 0x3C
    int right_margin_imageID;       // 0x40
    int bottom_left_margin_imageID; // 0x44
    int bottom_margin_imageID;      // 0x48
    int bottom_right_imageID;       // 0x4C
    int unk2;                       // 0x50
    int unk3;                       // 0x54
    int helper_width;               // 0x5C
    int helper_height;              // 0x60
} EqMinimapWindow;

typedef struct GameWindowMargins
{
    Window window;
    Window *worldWindow;    // 0x2C
    int top_margin_size;    // 0x30
    int left_margin_size;   // 0x34
    int game_window_width;  // 0x38
    int game_window_height; // 0x3C
} GameWindowMargins;

typedef struct MainWindow
{
    Window window;
    int unk;                           // 0x2C
    GameWindowMargins *gameWindow;     // 0x30
    Window *playerWindow;              // 0x34
    ContainerWindow *containersWindow; // 0x38
    Window *firstChildPlayerWindow;    // 0x3C
    Window *chatWindow;                // 0x40
    Window *resizeBarWindow;           // 0x44
} MainWindow;

typedef struct EditBoxWindow // 0x6C bytes
{
    Window window;
    char *text; // 0x2C
    int size;   // 0x30
    int unk[13];
    short unk2;
    short current_position;
} EditBoxWindow;

typedef struct ContainerBody
{
    Window window;
    int unk[5];
} ContainerBody;

typedef struct ContainerBoxWindow // 0x70
{
    Window window;
    int unk3[18]; // 0x2C
} ContainerBoxWindow;

#endif STRUCTS
