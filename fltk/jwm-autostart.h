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

#ifndef jwm_autostart_h
#define jwm_autostart_h
#include <FL/Fl.H>
#include <libintl.h>
#include <string>
#include <stdlib.h>
#include <iostream>
#include "../include/jwmrc.hpp"
#include "../include/autostart.hpp"
#include "../include/fltkfunctions.hpp"
#include "../include/ui.hpp"
#include <FL/Fl_Select_Browser.H>
#include "../data/icons/jsm-autostart.xpm"
#include <FL/Fl_Double_Window.H>
#include <FL/Fl_Scroll.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Tabs.H>
#include <FL/Fl_Group.H>
#include <FL/Fl_Browser.H>

class AutostartUI : public JSM_Autostart {
public:
  Fl_Double_Window* make_window();
  Fl_Double_Window *autostart_window;
  Fl_Input *program_name;
private:
  inline void cb_Cancel_i(Fl_Button*, void*);
  static void cb_Cancel(Fl_Button*, void*);
public:
  Fl_Button *save_button;
private:
  inline void cb_save_button_i(Fl_Button*, void*);
  static void cb_save_button(Fl_Button*, void*);
public:
  Fl_Button *add_item;
private:
  inline void cb_add_item_i(Fl_Button*, void*);
  static void cb_add_item(Fl_Button*, void*);
public:
  Fl_Button *remove_item;
private:
  inline void cb_remove_item_i(Fl_Button*, void*);
  static void cb_remove_item(Fl_Button*, void*);
public:
  Fl_Tabs *tabbies;
  Fl_Group *jwm_tab;
  Fl_Browser *autoStartBrowser;
  Fl_Group *xdg_tab;
  Fl_Browser *xdgbrowser;
private:
  inline void cb_xdgbrowser_i(Fl_Browser*, void*);
  static void cb_xdgbrowser(Fl_Browser*, void*);
public:
  Fl_Button *config_item;
private:
  inline void cb_config_item_i(Fl_Button*, void*);
  static void cb_config_item(Fl_Button*, void*);
};
#endif
