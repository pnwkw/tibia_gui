#include "gui_class.h"
#include "static_class_functions.h"

void _cdecl GUIcore::RegisterChild(GUIcore *child)
{
    return draw_gui_item((void *)this, (void *)child);
}

void _cdecl GUIcore::ShowChild(GUIcore *child, DWORD x, DWORD y, DWORD width, DWORD height)
{
    return show_gui_item((void *)this, (void *)child, x, y, width, height);
}

void _cdecl GUIcore::SetChildPos(GUIcore *child, int x, int y)
{
    return set_child_pos((void *)this, (void *)child, x, y);
}

GUIEditBox::GUIEditBox(DWORD max_len, DWORD start_len)
{
    create_editbox((void *)this, max_len, start_len);
}

GUINameBox::GUINameBox(int font, int nRed, int nBlue, int nGreen, int algin, char *name)
{
    create_namebox((void *)this, font, nRed, nBlue, nGreen, algin, name);
}

GUIIconBox::GUIIconBox(int icon)
{
    create_iconbox((void *)this, icon);
}

GUIContainerBox::GUIContainerBox(int identifier, GUIcore *body, int resizeable, int arg4)
{
    create_containerbox((void *)this, identifier, (void *)body, resizeable, arg4);
}

void GUIContainerBox::RegisterCloseButton(GUIcore *child)
{
    window_reg_close((void *)this, (void *)child);
}

void GUIContainerBox::RegisterMinimiseButton(GUIcore *child)
{
    window_reg_minimise((void *)this, (void *)child);
}

void GUIContainerBox::RegisterIcon(GUIcore *child)
{
    window_reg_icon((void *)this, (void *)child);
}

void GUIContainerBox::RegisterNamePlate(GUIcore *child)
{
    window_reg_name((void *)this, (void *)child);
}

GUICheckBox::GUICheckBox(char *label, GUIcore *EventReciver, int arg3)
{
    create_checkbox((void *)this, label, (int)EventReciver, arg3);
}

GUIMiniButtonBox::GUIMiniButtonBox(int unk1, int unk2, int image_notclicked, int image_clicked, GUIcore *EventReciver, int eventID, char *description, int unk8)
{
    create_minibuttonbox((void *)this, unk1, unk2, image_notclicked, image_clicked, (int)EventReciver, eventID, description, unk8);
}

GUISkillBody::GUISkillBody()
{
    create_containerbody((void *)this);
}

GUIButtonBox::GUIButtonBox(int arg1, int arg2, char *label, int arg3, int arg4, GUIcore *EventReciver, int eventID, char *description)
{
    create_buttonbox((void *)this, arg1, arg2, label, arg3, arg4, (void *)EventReciver, eventID, description);
}

GUIBody::GUIBody(int arg1, int arg2)
{
    create_body((void *)this, arg1, arg2);
}

GUIBody::GUIBody()
{
    create_body2((void *)this);
}

GUIScroller::GUIScroller(int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7, int arg8, int arg9)
{
    create_scroller((void *)this, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9);
}

#define DO_SEND_CANCEL_FUNC_ADDR 0x53FE40
typedef void _tDoSendCancel(char *text, int type);

GUIEvent::GUIEvent()
{
    this->clicked = false;
}

void GUIEvent::guiItemFireEvent(int eventID)
{
    if (eventID == 0x22)
        this->clicked = !clicked;
}
