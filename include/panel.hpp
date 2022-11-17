/*                 Joe's Window Manager Configuration
 *
 * This program configures JWM using pugixml and FLTK
 *
 *         Copyright (C) 2016  Israel <israeldahl@gmail.com>
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 * This has been developed as a part of the ToriOS Project
 *
 *
 * You may redistribute this, but you must keep this comment in place
 * Jesus is my Lord, and if you don't like it feel free to ignore it.
 */
// generated by Fast Light User Interface Designer (fluid) version 1.0303

#ifndef panel_hpp
#define panel_hpp
//std
#include <libintl.h>
#include <string>
#include <algorithm>
#include <stdlib.h>
#include <iostream>
//mine
#include "jwmrc.hpp"
#include "fltkfunctions.hpp"
//FLTK
#include <FL/Fl.H>
#include <FL/Fl_Double_Window.H>
#include <FL/Fl_Scroll.H>
#include <FL/Fl_Menu_Button.H>
#include <FL/Fl_Tabs.H>
#include <FL/Fl_Group.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Browser.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Slider.H>
#include <FL/Fl_Value_Input.H>
#include <FL/Fl_Check_Button.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Output.H>
class JSM_Panel : public FLTK_FUNCTIONS
{
	public:
	//string
		std::string getAutoHide(int num);
		std::string getButtonTooltip(std::string item);
		std::string getClock(std::string timeString);
		std::string getClock();
		std::string getClockText(int position);
		std::string getImageMenu(std::string item);
		std::string getLabelMenu(std::string item);
		std::string getNextPanelPosition();
		std::string getThisPanelPosition();
		std::string getTrayStyleattribute(std::string item);
		std::string getItemVal(int position, std::string attribute);
		std::string Menu_Label(int num);

	//double
		double getItemWH(int position, std::string attribute);
		double setTaskW(int position);
		double getItemW(int position);
		double getSpacing(int position);
		double getTaskW(int position);
		double getItemH(int position);
		
	//unsigned int
		unsigned int switch_panel(Fl_Menu_Item *o);

	//int
		int getBorder();
		int getCoordinate(std::string xy);
		int getHeight();
		int getWidth();
		int taskLabeled(int position);

	//bool
		bool addApp(std::string element);
		bool addApp(std::string element, std::string attribute,std::string value,std::string text);
		bool addApp(std::string element,std::string attribute,std::string value);
		bool addButton(std::string icon,std::string execLine,std::string popup,int border);
		bool add_new_shortcut(Fl_Browser* shortcut_browser,Fl_Input* app_command,Fl_Input* tooltip,Fl_Box* icon_name,int border);
		bool addShortcut(std::string icon,std::string execLine,std::string popup,int border);
		bool style_gone();
		bool setClockText(int position,std::string text, std::string mask);
		bool setItemText(int position, std::string text);
		bool setTaskW(int value, int position);
		bool setItemH(int value,int position);
		bool setItemW(int value,int position);
		bool setItemWH(std::string attribute, int value,int position);
		bool setItemWH(std::string attribute, std::string value,int position);
		bool TRUEorFALSE(std::string boolean);
		bool toomanypanels();

	//void
//         A
		void addBattery();
		void addClock();
		void addIndicator(std::string indicator);
		void addNetworkMonitor();
		void add_new_menu();
		void addPager();
		void addPanel();
		void addSpacer(double w, double h, int position);
		void addTaskList();
		void addVolume();
		void app_command_CB(Fl_Input* o, Fl_Input* app_command);
		void autohide(Fl_Check_Button* autohide_check,Fl_Widget* choose_autohide);
		void autohide_position(std::string where,Fl_Output *autohide_pos);
//         C
		void changeClock(std::string style);
		void change_layer(std::string position,Fl_Output * layer);
		void changePanel(int number);
		void checkDock();
//         D
		void deleteBattery();
		void deleteNetworkMonitor();
		void deletePanel();
		void deleteSomeIndicator(std::string indicator);
		void deleteTrayButton(std::string text_to_find);
		void deleteVolume();
//         E
		void editButton(int whichbutton, std::string MENU,std::string PROG,std::string ICON,std::string LABEL,std::string MASK);
//         G
		void getTrayStyleattribute(std::string item,Fl_Output* list_out);
		void getColorFromItem(bool active, std::string element,std::string subelement,Fl_Button* o);
		void getGroupWin(Fl_Check_Button *o);
		void getIndicators(Fl_Browser* o);
		void getIndicatorsPopulate(Fl_Browser* o,std::vector<std::string> list);
//         H
		void hide_menu(Fl_Menu_Item * o, int whichOne);
//         I
		void icon_for_desktop(Fl_Browser* shortcut_browser,Fl_Input* app_command,Fl_Box* icon_name,Fl_Input* tooltip,Fl_Button* app_icon_box);
		void input_width_height_border(Fl_Slider *slider_o, Fl_Value_Input *input_o, const char* dimension);
//         L
		void labelMenu(std::string testNum,std::string newLabel);
		void layout(std::string position,Fl_Output *layOut);
		void listIndicators(Fl_Browser *o);
//         N
		void new_panel_items(Fl_Browser *o);
		void num_desktop_wh_CB(std::string whichone, int value,Fl_Value_Input* num_desktop_w, Fl_Value_Input* num_desktop_h);
//         P
		void panel_v(int num, Fl_Output * valign);
		void panel_h(int num, Fl_Output * valign);
		void panel_hv(std::string attrib, int num, Fl_Output * valign);
		void panel_label(Fl_Menu_Button *o);
		void panel_menu_button_label(Fl_Menu_Button* o);
		void panel_position(std::string position);
		void populateClocks(Fl_Browser* o);
//         R
		void refresh_app_browser(Fl_Browser* app_browser);
		void remove_app(Fl_Browser* app_browser);
		void removeAutostart(std::string exec);
		void removeIndicator(Fl_Browser* o);
//         S
		void setImageMenu(std::string testNum,std::string icon);
		void setItemBool(int position, int value);
		void setCoordinate(std::string xy, int value);
		void setTaskListValue(std::string attribute, std::string value);
		void setValue(std::string attribute, std::string value);
		void switchButton(std::string OLD,std::string NEW,std::string tooltip,std::string icon,std::string label);
//         W
		void width_height_border(Fl_Slider *slider_o, Fl_Value_Input *input_o, const char* dimension);
};
#endif