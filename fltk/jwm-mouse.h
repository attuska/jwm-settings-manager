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
// generated by Fast Light User Interface Designer (fluid) version 1.0304

#ifndef jwm_mouse_h
#define jwm_mouse_h
#include <FL/Fl.H>
//Many thanks to flSynclient (c) 2006 Matteo Lucarelli <matteo@matteolucarelli.net>
#include <libintl.h>
#include <string>
#include <stdlib.h>
#include <iostream>
#include "../include/jwmrc.hpp"
#include <getopt.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <FL/filename.H>
#include <FL/fl_draw.H>
#include <FL/fl_message.H>
#include <FL/Fl_Select_Browser.H>
#include "../data/icons/jsm-mouse.xpm"
#include <sstream>
#include <fstream>
#include "../include/fltkfunctions.hpp"
#include <FL/Fl_Double_Window.H>
#include <FL/Fl_Browser.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Slider.H>
#include <FL/Fl_Value_Input.H>
#include <FL/Fl_Scroll.H>
#include <FL/Fl_Tabs.H>
#include <FL/Fl_Group.H>
#include <FL/Fl_Choice.H>
#include <FL/Fl_Check_Button.H>
#include <FL/Fl_Value_Slider.H>
#include <FL/Fl_Value_Output.H>

class MouseUI : public FLTK_FUNCTIONS {
public:
  bool verbose;int m_pid;bool deltaChanged;bool doubleChanged;bool JWM; 
  Fl_Double_Window* cursors_window();
  Fl_Double_Window *CURSOR_win;
  Fl_Browser *cursor_browser;
  Fl_Button *cancel_button2;
private:
  inline void cb_cancel_button2_i(Fl_Button*, void*);
  static void cb_cancel_button2(Fl_Button*, void*);
public:
  Fl_Button *save_button2;
private:
  inline void cb_save_button2_i(Fl_Button*, void*);
  static void cb_save_button2(Fl_Button*, void*);
public:
  Fl_Double_Window* error_window();
private:
  inline void cb_QUIT_i(Fl_Button*, void*);
  static void cb_QUIT(Fl_Button*, void*);
public:
  Fl_Double_Window* jwm_window();
  Fl_Slider *double_click_slider2;
private:
  inline void cb_double_click_slider2_i(Fl_Slider*, void*);
  static void cb_double_click_slider2(Fl_Slider*, void*);
public:
  Fl_Slider *delta_slider2;
private:
  inline void cb_delta_slider2_i(Fl_Slider*, void*);
  static void cb_delta_slider2(Fl_Slider*, void*);
public:
  Fl_Value_Input *delta_v2;
private:
  inline void cb_delta_v2_i(Fl_Value_Input*, void*);
  static void cb_delta_v2(Fl_Value_Input*, void*);
public:
  Fl_Value_Input *double_v2;
private:
  inline void cb_double_v2_i(Fl_Value_Input*, void*);
  static void cb_double_v2(Fl_Value_Input*, void*);
public:
  Fl_Button *save_button;
private:
  inline void cb_save_button_i(Fl_Button*, void*);
  static void cb_save_button(Fl_Button*, void*);
public:
  Fl_Button *cancel_button3;
private:
  inline void cb_cancel_button3_i(Fl_Button*, void*);
  static void cb_cancel_button3(Fl_Button*, void*);
public:
  Fl_Button *cursors_button;
private:
  inline void cb_cursors_button_i(Fl_Button*, void*);
  static void cb_cursors_button(Fl_Button*, void*);
public:
  Fl_Double_Window* make_window();
  Fl_Double_Window *mouse_window;
  Fl_Choice *TouchpadOff;
private:
  inline void cb_TouchpadOff_i(Fl_Choice*, void*);
  static void cb_TouchpadOff(Fl_Choice*, void*);
  static unsigned char menu_TouchpadOff_i18n_done;
  static Fl_Menu_Item menu_TouchpadOff[];
public:
  Fl_Check_Button *GuestMouseOff;
private:
  inline void cb_GuestMouseOff_i(Fl_Check_Button*, void*);
  static void cb_GuestMouseOff(Fl_Check_Button*, void*);
public:
  Fl_Check_Button *CircularPad;
private:
  inline void cb_CircularPad_i(Fl_Check_Button*, void*);
  static void cb_CircularPad(Fl_Check_Button*, void*);
public:
  Fl_Value_Slider *FingerLowHigh;
private:
  inline void cb_FingerLowHigh_i(Fl_Value_Slider*, void*);
  static void cb_FingerLowHigh(Fl_Value_Slider*, void*);
public:
  Fl_Value_Slider *ClickTime;
private:
  inline void cb_ClickTime_i(Fl_Value_Slider*, void*);
  static void cb_ClickTime(Fl_Value_Slider*, void*);
public:
  Fl_Value_Slider *EmulateMidButtonTime;
private:
  inline void cb_EmulateMidButtonTime_i(Fl_Value_Slider*, void*);
  static void cb_EmulateMidButtonTime(Fl_Value_Slider*, void*);
public:
  Fl_Choice *TapButton1;
private:
  inline void cb_TapButton1_i(Fl_Choice*, void*);
  static void cb_TapButton1(Fl_Choice*, void*);
  static unsigned char menu_TapButton1_i18n_done;
  static Fl_Menu_Item menu_TapButton1[];
public:
  Fl_Choice *TapButton2;
private:
  inline void cb_TapButton2_i(Fl_Choice*, void*);
  static void cb_TapButton2(Fl_Choice*, void*);
  static unsigned char menu_TapButton2_i18n_done;
  static Fl_Menu_Item menu_TapButton2[];
public:
  Fl_Choice *TapButton3;
private:
  inline void cb_TapButton3_i(Fl_Choice*, void*);
  static void cb_TapButton3(Fl_Choice*, void*);
  static unsigned char menu_TapButton3_i18n_done;
  static Fl_Menu_Item menu_TapButton3[];
public:
  Fl_Choice *LTCornerButton;
private:
  inline void cb_LTCornerButton_i(Fl_Choice*, void*);
  static void cb_LTCornerButton(Fl_Choice*, void*);
  static unsigned char menu_LTCornerButton_i18n_done;
  static Fl_Menu_Item menu_LTCornerButton[];
public:
  Fl_Choice *RTCornerButton;
private:
  inline void cb_RTCornerButton_i(Fl_Choice*, void*);
  static void cb_RTCornerButton(Fl_Choice*, void*);
  static unsigned char menu_RTCornerButton_i18n_done;
  static Fl_Menu_Item menu_RTCornerButton[];
public:
  Fl_Choice *LBCornerButton;
private:
  inline void cb_LBCornerButton_i(Fl_Choice*, void*);
  static void cb_LBCornerButton(Fl_Choice*, void*);
  static unsigned char menu_LBCornerButton_i18n_done;
  static Fl_Menu_Item menu_LBCornerButton[];
public:
  Fl_Choice *RBCornerButton;
private:
  inline void cb_RBCornerButton_i(Fl_Choice*, void*);
  static void cb_RBCornerButton(Fl_Choice*, void*);
  static unsigned char menu_RBCornerButton_i18n_done;
  static Fl_Menu_Item menu_RBCornerButton[];
public:
  Fl_Value_Slider *MaxTapTime;
private:
  inline void cb_MaxTapTime_i(Fl_Value_Slider*, void*);
  static void cb_MaxTapTime(Fl_Value_Slider*, void*);
public:
  Fl_Value_Slider *MaxDoubleTapTime;
private:
  inline void cb_MaxDoubleTapTime_i(Fl_Value_Slider*, void*);
  static void cb_MaxDoubleTapTime(Fl_Value_Slider*, void*);
public:
  Fl_Value_Slider *MaxTapMove;
private:
  inline void cb_MaxTapMove_i(Fl_Value_Slider*, void*);
  static void cb_MaxTapMove(Fl_Value_Slider*, void*);
public:
  Fl_Check_Button *VertTwoFingerScroll;
private:
  inline void cb_VertTwoFingerScroll_i(Fl_Check_Button*, void*);
  static void cb_VertTwoFingerScroll(Fl_Check_Button*, void*);
public:
  Fl_Check_Button *HorizTwoFingerScroll;
private:
  inline void cb_HorizTwoFingerScroll_i(Fl_Check_Button*, void*);
  static void cb_HorizTwoFingerScroll(Fl_Check_Button*, void*);
public:
  Fl_Check_Button *UpDownScrolling;
private:
  inline void cb_UpDownScrolling_i(Fl_Check_Button*, void*);
  static void cb_UpDownScrolling(Fl_Check_Button*, void*);
public:
  Fl_Check_Button *LeftRightScrolling;
private:
  inline void cb_LeftRightScrolling_i(Fl_Check_Button*, void*);
  static void cb_LeftRightScrolling(Fl_Check_Button*, void*);
public:
  Fl_Check_Button *CircularScrolling;
private:
  inline void cb_CircularScrolling_i(Fl_Check_Button*, void*);
  static void cb_CircularScrolling(Fl_Check_Button*, void*);
public:
  Fl_Value_Slider *VertScrollDelta;
private:
  inline void cb_VertScrollDelta_i(Fl_Value_Slider*, void*);
  static void cb_VertScrollDelta(Fl_Value_Slider*, void*);
public:
  Fl_Value_Slider *HorizScrollDelta;
private:
  inline void cb_HorizScrollDelta_i(Fl_Value_Slider*, void*);
  static void cb_HorizScrollDelta(Fl_Value_Slider*, void*);
public:
  Fl_Value_Slider *CircScrollDelta;
private:
  inline void cb_CircScrollDelta_i(Fl_Value_Slider*, void*);
  static void cb_CircScrollDelta(Fl_Value_Slider*, void*);
public:
  Fl_Choice *CircScrollTrigger;
private:
  inline void cb_CircScrollTrigger_i(Fl_Choice*, void*);
  static void cb_CircScrollTrigger(Fl_Choice*, void*);
  static unsigned char menu_CircScrollTrigger_i18n_done;
  static Fl_Menu_Item menu_CircScrollTrigger[];
public:
  Fl_Value_Slider *EdgeMotionMinSpeed;
private:
  inline void cb_EdgeMotionMinSpeed_i(Fl_Value_Slider*, void*);
  static void cb_EdgeMotionMinSpeed(Fl_Value_Slider*, void*);
public:
  Fl_Value_Slider *EdgeMotionMaxSpeed;
private:
  inline void cb_EdgeMotionMaxSpeed_i(Fl_Value_Slider*, void*);
  static void cb_EdgeMotionMaxSpeed(Fl_Value_Slider*, void*);
public:
  Fl_Value_Slider *EdgeMotionMinMaxZ;
private:
  inline void cb_EdgeMotionMinMaxZ_i(Fl_Value_Slider*, void*);
  static void cb_EdgeMotionMinMaxZ(Fl_Value_Slider*, void*);
public:
  Fl_Value_Output *TopEdge;
private:
  inline void cb_Calibrate_i(Fl_Button*, void*);
  static void cb_Calibrate(Fl_Button*, void*);
public:
  Fl_Value_Output *BottomEdge;
private:
  inline void cb_Calibrate1_i(Fl_Button*, void*);
  static void cb_Calibrate1(Fl_Button*, void*);
public:
  Fl_Value_Output *LeftEdge;
private:
  inline void cb_Calibrate2_i(Fl_Button*, void*);
  static void cb_Calibrate2(Fl_Button*, void*);
public:
  Fl_Value_Output *RightEdge;
private:
  inline void cb_Calibrate3_i(Fl_Button*, void*);
  static void cb_Calibrate3(Fl_Button*, void*);
public:
  Fl_Value_Slider *MinSpeed;
private:
  inline void cb_MinSpeed_i(Fl_Value_Slider*, void*);
  static void cb_MinSpeed(Fl_Value_Slider*, void*);
public:
  Fl_Value_Slider *MaxSpeed;
private:
  inline void cb_MaxSpeed_i(Fl_Value_Slider*, void*);
  static void cb_MaxSpeed(Fl_Value_Slider*, void*);
public:
  Fl_Value_Slider *AccelFactor;
private:
  inline void cb_AccelFactor_i(Fl_Value_Slider*, void*);
  static void cb_AccelFactor(Fl_Value_Slider*, void*);
public:
  Fl_Slider *double_click_slider;
private:
  inline void cb_double_click_slider_i(Fl_Slider*, void*);
  static void cb_double_click_slider(Fl_Slider*, void*);
public:
  Fl_Value_Input *double_v;
private:
  inline void cb_double_v_i(Fl_Value_Input*, void*);
  static void cb_double_v(Fl_Value_Input*, void*);
public:
  Fl_Slider *delta_slider;
private:
  inline void cb_delta_slider_i(Fl_Slider*, void*);
  static void cb_delta_slider(Fl_Slider*, void*);
public:
  Fl_Value_Input *delta_v;
private:
  inline void cb_delta_v_i(Fl_Value_Input*, void*);
  static void cb_delta_v(Fl_Value_Input*, void*);
public:
  Fl_Button *cancel_button;
private:
  inline void cb_cancel_button_i(Fl_Button*, void*);
  static void cb_cancel_button(Fl_Button*, void*);
public:
  Fl_Button *ok_button;
private:
  inline void cb_ok_button_i(Fl_Button*, void*);
  static void cb_ok_button(Fl_Button*, void*);
public:
  Fl_Button *main_cursors_button;
private:
  inline void cb_main_cursors_button_i(Fl_Button*, void*);
  static void cb_main_cursors_button(Fl_Button*, void*);
  inline void cb_QUIT1_i(Fl_Button*, void*);
  static void cb_QUIT1(Fl_Button*, void*);
public:
  void add_to_profile();
  bool checksynclient();
  double convert(std::string number);
  std::string convert(double number);
  void CalibrateEdge(int edge);
  bool isJWM();
  void JWMmouse();
  int numfromstring(std::string text);
  int parseline(char *line, char **argv, int maxarg);
  void parsesynclientoutput(std::string filename);
  void populate_cusors();
  int readsynclientoutput();
  void save_cursors();
  void synclient(const char* field, double value);
  void SaveSettings();
};
int main();
#endif