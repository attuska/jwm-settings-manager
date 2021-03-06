#include "../include/keyboard.hpp"
//Void//////////////////////////////////////////////////////////////////
JWM_Keyboard::JWM_Keyboard ()
{
	DELIM='@';
	DELIMITER=DELIM;
}
void JWM_Keyboard::addKey(std::string key, std::string shortcut){
	debug_out("void addKey(std::string "+ key+", std::string " +shortcut+ ")");
    if(!addElementWithTextAndAttribute("Key","key",key,shortcut)){debug_out("Add Key Failed");}
}
void JWM_Keyboard::addKey(std::string keyMod, std::string key, std::string shortcut){
	debug_out("void addKey(std::string "+keyMod+", std::string "+key+", std::string "+shortcut=")");
    if(!addElementWithTextAndAttribute("Key","key",key,"mask",keyMod,shortcut)){debug_out("Add Key Failed");}
}
void JWM_Keyboard::changemod(std::string mod,Fl_Output* Aout,Fl_Output* Bout){
	if(OutputIsEmpty(Aout)){Aout->value(mod.c_str());}
	else if(OutputIsEmpty(Bout)){Bout->value(mod.c_str());}
	else{debug_out("All Mods are filled");}
}
void JWM_Keyboard::changemod(std::string mod,Fl_Output* Aout,Fl_Output* Bout,Fl_Output* Cout){
	if(OutputIsEmpty(Aout)){Aout->value(mod.c_str());}
	else if(OutputIsEmpty(Bout)){Bout->value(mod.c_str());}
	else if(OutputIsEmpty(Cout)){Cout->value(mod.c_str());}
	else{debug_out("All Mods are filled");}
}
bool JWM_Keyboard::configureKey(std::string keyShortcut, std::string newmod1, std::string newmod2, std::string newmod3, std::string newkey, std::string newaction){
	debug_out("void configureKey(std::string "+keyShortcut+", std::string "+newmod1+", std::string "+newmod2+", std::string "+newmod3+", std::string "+newkey+", std::string "+newaction+")");
    if(keyShortcut.compare("")==0){return false;}
    std::string mod1FromProg,
				mod2FromProg,
				mod3FromProg,
				keyFromProg,
				actionFromProg,
				totalMod,
				totalNewMod;
    totalNewMod=newmod1+newmod2+newmod3;
    mod1FromProg=getMod1(keyShortcut);
    mod2FromProg=getMod2(keyShortcut);
    mod3FromProg=getMod3(keyShortcut);
    totalMod= mod1FromProg+mod2FromProg+mod3FromProg;
    keyFromProg=getKey(keyShortcut);
    actionFromProg=getAction(keyShortcut);
    pugi::xml_node node=compareNode("Key","key",keyFromProg,"mask",totalMod,actionFromProg);
    if(node){
		//found it!
		if(totalNewMod.compare("")!=0)
		{
			if(!node.attribute("mask")){node.append_attribute("mask");}
			node.attribute("mask").set_value(totalNewMod.c_str());
		}
		if(!node.attribute("key")){node.append_attribute("key");} //This should NEVER happen..
		node.attribute("key").set_value(keyShortcut.c_str());
		node.set_value(newaction.c_str());
		return saveChangesTemp();
    }
	else{
		debug_out("Didn't find node key="+keyFromProg+" mask="+totalMod+" text="+actionFromProg);
	}
	return false;
}
void JWM_Keyboard::Choose_Action(Fl_Input* action_name){
	debug_out("void Choose_Action(Fl_Input* action_name)");
	std::string result = choose_a_program();
	debug_out(result);
	std::string exec = "exec:";
	exec+=result;
	action_name->value(exec.c_str());
}
void JWM_Keyboard::deleteKey(std::string keyShortcut){
	debug_out("void deleteKey(std::string "+keyShortcut+")");
    if(keyShortcut.compare("")==0){return;}
    std::string mod1FromProg,mod2FromProg,mod3FromProg,keyFromProg,actionFromProg,totalMod;
    mod1FromProg=getMod1(keyShortcut);
    mod2FromProg=getMod2(keyShortcut);
    mod3FromProg=getMod3(keyShortcut);
    totalMod= mod1FromProg+mod2FromProg+mod3FromProg;
    keyFromProg=getKey(keyShortcut);
    actionFromProg=getAction(keyShortcut);
    removeElementCompare2Attr("Key","key",keyFromProg,"mask",totalMod,actionFromProg);
}
void JWM_Keyboard::key_event(Fl_Input* o, Fl_Output* out, Fl_Output* modder){
	debug_out("void key_event(Fl_Input* o, Fl_Output* out)");
	int k = Fl::event_key();
	std::string modifier_text =getINPUT(o);
	std::string key_display="";
	const char* event_text = Fl::event_text();
	int l_shift = Fl::event_key(FL_Shift_R);
	int r_shift = Fl::event_key(FL_Shift_L);
	int l_control = Fl::event_key(FL_Control_R);
	int r_control = Fl::event_key(FL_Control_L);
	int l_meta = Fl::event_key(FL_Meta_L);
	int r_meta = Fl::event_key(FL_Meta_R);
	int l_alt = Fl::event_key(FL_Alt_L);
	int r_alt = Fl::event_key(FL_Alt_R);
	bool alt = false;
	bool shift = false;
	bool meta = false;
	bool ctrl = false;
	if(r_alt||l_alt){alt=true;
		debug_out("MOD=Alt");
		key_display="Alt ";
		mod_cb("A",modder);
	}
	if(l_shift||r_shift){
		debug_out("MOD=Shift");
		mod_cb("S",modder);
		key_display="Shift +";
		shift=true;
	}
	if(l_control||r_control){
		debug_out("MOD=Control");
		key_display="Control +";
		mod_cb("C",modder);
		ctrl=true;
	}
	if(l_meta||r_meta){meta=true;
		debug_out("MOD=Meta/Super");
		key_display="Super ";
		mod_cb("4",modder);
	}
	if(event_text==NULL){
		debug_out("Key event is NULL");
		return;
	}
	key_display+=event_text;
	debug_out("Key display = "+key_display);
	if((key_display.compare("")!=0)&&(k<=256)){
		out->value(event_text);
		//out->show();
		o->value(key_display.c_str());
	}
}
void JWM_Keyboard::keyLayoutPopulate(Fl_Browser *o){keyPopulate(o,"layout");}
void JWM_Keyboard::keyModelPopulate(Fl_Browser *o){keyPopulate(o,"model");}
void JWM_Keyboard::keyOptionPopulate(Fl_Browser *o){keyPopulate(o,"option");}
void JWM_Keyboard::keyPopulate(Fl_Browser *o,std::string thingToGet){
	debug_out("void keyPopulate(Fl_Browser *o,std::string "+thingToGet+")");
	std::string list=linuxcommon::term_out("localectl list-x11-keymap-"+thingToGet+"s --no-pager");
	if(list.compare("")==0){
		std::string file="/usr/share/X11/xkb/rules/base.lst";
		if(!linuxcommon::test_file(file)){
			errorOUT("Cannot create the list for "+thingToGet);
			return;
		}
		std::vector<std::string> vector_to_check=linuxcommon::file_to_vector(file);
		bool start=false;
		std::string fileItem="! "+thingToGet;
		for( std::vector<std::string>::iterator it = vector_to_check.begin();
		it!=vector_to_check.end();
		++it){
			std::string tmp=*it;
			unsigned int founder=tmp.find(fileItem);
			unsigned int flounder=tmp.find("! ");
			if(flounder<tmp.length()){start=false;}
			if(start){
				if(list.compare("")==0){if(tmp.compare("")!=0)list=tmp;}
				else{if(tmp.compare("")!=0)list=list+"\n"+tmp;}
			}
			if(founder<tmp.length()){start=true;}
		}
	}
	populateBrowserWithString(o,list);
}
void JWM_Keyboard::mod_cb(std::string mod, Fl_Output *o){
  if(mod.compare("")!=0){
    o->value(mod.c_str());
    o->redraw();
  }
}
void JWM_Keyboard::mod2_cb(std::string mod, Fl_Output *o){
	if(mod.compare("")==0){return;}
	o->value(mod.c_str());
}
void JWM_Keyboard::remove_key(Fl_Browser* o){
	debug_out("void remove_key(Fl_Browser* o)");
	const char* mykey = o->text(o->value());
	if(mykey==NULL){return;}
	std::string keyShortcut = mykey;
	if (keyShortcut.compare("")!=0){
		debug_out("Delete: "+keyShortcut);
		deleteKey(keyShortcut);
		o->clear();
		getKeys(o);
		o->redraw();
	}
	else{
		fl_message("Please click on an item to remove!");
	}
}
void JWM_Keyboard::setLayout(Fl_Input *layoutput, Fl_Input *modeloutput, Fl_Input *optionoutput){
	debug_out("void setLayout(Fl_Input *layoutput, Fl_Input *modeloutput, Fl_Input *optionoutput)");
	someLayout(layoutput, modeloutput, optionoutput,true);
}

void JWM_Keyboard::someLayout(Fl_Input *layoutput, Fl_Input *modeloutput, Fl_Input *optionoutput, bool save){
	std::string SAVE="Don't Save";
	if(save){SAVE="SAVE!";}
	debug_out("void someLayout(Fl_Input *layoutput, Fl_Input *modeloutput, Fl_Input *optionoutput, "+SAVE+")");
	std::string command="localectl";
	const char* layout=layoutput->value();
	const char* model=modeloutput->value();
	const char* option=optionoutput->value();
	std::string LAYOUT,MODEL,OPTION;
	if(layout!=NULL){LAYOUT=layout;}
	if(model!=NULL){MODEL=model;}
	if(option!=NULL){OPTION=option;}
	bool thisExec=isExec(command);
	if(!thisExec){
		command="setxkbmap";
		thisExec=isExec(command);
		if(!thisExec){
			errorOUT("Did not find an appropriate program to set keyboard maping");
			return;
		}
	}
	if(save){
		bool sysd=false;
		if(command.compare("localectl")==0){
			sysd=true;
			command+=" set-x11-keymap";
			if(LAYOUT.compare("")!=0){command=command+" "+LAYOUT;}
			if(MODEL.compare("")!=0){command=command+" "+MODEL;}
			if(OPTION.compare("")!=0){command=command+" "+OPTION;}
		}
		else{
			if(LAYOUT.compare("")!=0){command=command+" -layout "+LAYOUT;}
			if(MODEL.compare("")!=0){command=command+" -model "+MODEL;}
			if(OPTION.compare("")!=0){command=command+" -option "+OPTION;}
			std::string BASHRC=linuxcommon::home_path();
			if(BASHRC.compare("")!=0){
				//TODO something better than this
				BASHRC+=".bashrc";
				if(!linuxcommon::append_string_to_file(command,BASHRC)){errorOUT("Could not save "+command+" to "+BASHRC);}
			}
		}
	}
	else{
		if(command.compare("localectl")==0){
			command+=" set-x11-keymap";
			if(LAYOUT.compare("")!=0){command=command+" "+LAYOUT;}
			if(MODEL.compare("")!=0){command=command+" "+MODEL;}
			if(OPTION.compare("")!=0){command=command+" "+OPTION;}
		}
		else{
			if(LAYOUT.compare("")!=0){command=command+" -layout "+LAYOUT;}
			if(MODEL.compare("")!=0){command=command+" -model "+MODEL;}
			if(OPTION.compare("")!=0){command=command+" -option "+OPTION;}
		}
		
	}
	int retval=linuxcommon::run_a_program(command);
	if(retval!=0){errorOUT("Could not run "+command);}
}

void JWM_Keyboard::testLayout(Fl_Input *layoutput, Fl_Input *modeloutput, Fl_Input *optionoutput){
	debug_out("void testLayout(Fl_Input *layoutput, Fl_Input *modeloutput, Fl_Input *optionoutput)");
	someLayout(layoutput, modeloutput, optionoutput,false);
}
//String////////////////////////////////////////////////////////////////
std::string JWM_Keyboard::fixLayoutString(Fl_Browser *o){
	debug_out("std::string fixLayoutString(Fl_Browser *o)");
	std::string retval;
	if(checkFlBrowserItem(o)){
	  const char* val =o->text(o->value());
	  retval=val;
	  unsigned int exclaim=retval.find("!");
	  if(exclaim==0){return "";}
	  unsigned int finder=retval.find("  ");
	  if(finder<retval.length()){retval=retval.erase(finder,2);}
	  finder=retval.find(" ");
	  if(finder<retval.length()){retval=retval.erase(finder,std::string::npos);}
	}
	return retval;
}

std::string JWM_Keyboard::getAction(std::string keyShortcut){
	debug_out("std::string getAction(std::string "+keyShortcut+")");
    if(keyShortcut.compare("")==0){return "";}
    return getMod(keyShortcut,4);
}

std::string JWM_Keyboard::getKey(std::string keyShortcut){
	debug_out("std::string getKey(std::string "+keyShortcut+")");
    if(keyShortcut.compare("")==0){return "";}
    return getMod(keyShortcut,0);
}

std::string JWM_Keyboard::getLayout(Fl_Input *o,std::string whichOne){
	debug_out("std::string getLayout()");
	std::string test_command=linuxcommon::term_out("which localectl");
	std::string command="localectl";
	if(test_command.compare("")==0){
		test_command=linuxcommon::term_out("which setxkbmap");
		command="setxkbmap";
	}
	if(test_command.compare("")==0){return "";}
	std::string layout;
	if(command.compare("setxkbmap")==0){
		command+=" -query";
		layout=linuxcommon::term_out(command);
	}
	else{
		command+=" status";
		layout=linuxcommon::term_out(command);
	}
	std::vector<std::string> STRING_VEC=linuxcommon::delimiter_vector_from_string(layout,"\n");
	for( std::vector<std::string>::iterator it = STRING_VEC.begin();
		it!=STRING_VEC.end();
		++it){
			std::string tmp=*it;
			std::transform(tmp.begin(),tmp.end(),tmp.begin(), ::tolower);
			unsigned int finder = tmp.find(whichOne);
			if(finder<tmp.length()){
				finder = tmp.find(":");
				if(finder<tmp.length()){
					tmp=tmp.substr(finder+1,std::string::npos);
				}
				layout=tmp;
			}
		}
	return layout;
}

std::string JWM_Keyboard::getMod(std::string keyShortcut,unsigned int which=1){
	debug_out("std::string getMod(std::string "+keyShortcut+")");
	if(keyShortcut.compare("")==0){return "";}
	std::string keymod =keyShortcut;
	std::vector<std::string> T= linuxcommon::delimiter_vector_from_string(keyShortcut,DELIMITER);
	if(which>=T.size())
		return "";
	std::string tmp=T.at(which);
	debug_out("Value="+tmp);
}

std::string JWM_Keyboard::getMod1(std::string keyShortcut){
	debug_out("std::string getMod1(std::string "+keyShortcut+")");
	if(keyShortcut.compare("")==0){return "";}
	return getMod(keyShortcut,1);

}

std::string JWM_Keyboard::getMod2(std::string keyShortcut){
	debug_out("std::string getMod2(std::string "+keyShortcut+")");
	if(keyShortcut.compare("")==0){return "";}
	return getMod(keyShortcut,2);
}

std::string JWM_Keyboard::getMod3(std::string keyShortcut){
	debug_out("std::string getMod3(std::string "+keyShortcut+")");
	if(keyShortcut.compare("")==0){return "";}
	return getMod(keyShortcut,3);
}

std::string JWM_Keyboard::getINPUT(Fl_Input *o){
	debug_out("std::string getINPUT(Fl_Input *o)");
	if(!o->visible())
	{
		debug_out("input not visible");
		return "";
	}
	const char* out=o->value();
	if(out==NULL)
	{
		debug_out("input value is NULL");
		return "";
	}
	std::string outer=out;
	debug_out("INPUT="+outer);
	return outer;
}
std::string JWM_Keyboard::getOUTPUT(Fl_Output *o){
	debug_out("std::string getOUTPUT(Fl_Output *o)");
	if(!o->visible()){return "";}
	const char* out=o->value();
	if(out==NULL){return "";}
	std::string outer=out;
	debug_out("OUTPUT="+outer);
	return outer;
}

std::string JWM_Keyboard::grabbedKey(){
    struct termios oldSettings, newSettings;
    tcgetattr( fileno( stdin ), &oldSettings );
    newSettings = oldSettings;
    newSettings.c_lflag &= (~ICANON & ~ECHO);
    tcsetattr( fileno( stdin ), TCSANOW, &newSettings );
    char c;
    while ( 1 ){
        fd_set set;
        struct timeval tv;

        tv.tv_sec = 10;
        tv.tv_usec = 0;

        FD_ZERO( &set );
        FD_SET( fileno( stdin ), &set );

        int res = select( fileno( stdin )+1, &set, NULL, NULL, &tv );

        if( res > 0 ){
            std::cout<<"Input available"<<std::endl;
            int thisread = read( fileno( stdin ), &c, 1 );
            if(thisread !=0){std::cerr<< gettext("read input command did not return 0")<<std::endl;}
        }
        else if( res < 0 )
        {
            perror( "select error" );
            break;
        }
        else
        {
            std::cout<<"Select timeout"<<std::endl;
        }
    }
    std::string result = "";
    result+= c;
    tcsetattr( fileno( stdin ), TCSANOW, &oldSettings );
    return result;

}

std::string JWM_Keyboard::oldvalue(Fl_Output* old_action, Fl_Output* current_key,Fl_Output* current_mod1,Fl_Output* current_mod2,Fl_Output* current_mod3){
	std::string temp;
	const char* mod1=current_mod1->value();
	if(mod1!=NULL){temp=mod1;}
	const char* mod2=current_mod2->value();
	if(mod2!=NULL){temp+=mod2;}
	const char* mod3=current_mod3->value();
	if(mod3!=NULL){temp+=mod3;}
	const char* keychar=current_key->value();
	if(keychar!=NULL){
		std::string keycurrent=keychar;
		if(temp.compare("")==0)temp=" "+DELIMITER+keycurrent;
		else{temp=temp+DELIMITER+keycurrent;}
	}
	else{temp+=" "+DELIMITER;}
	const char* actionian=old_action->value();
	if(actionian!=NULL){temp=temp+DELIMITER+ actionian;}
	else{temp+=(DELIMITER +" ");}
	temp+=DELIMITER;
	return temp;
}
//Boolean///////////////////////////////////////////////////////////////
bool JWM_Keyboard::add_cb(Fl_Input *action_name, Fl_Output *key_output, Fl_Output *mod_output, Fl_Output *mod2_output, Fl_Output * mod3_output, Fl_Browser *o){
	debug_out("void add_cb(Fl_Input *action_name,Fl_Output *key_output,Fl_Output *mod_output,Fl_Browser *o)");
	std::string action,keyInput,mod;
	const char* testAction=action_name->value();
	if(testAction!=NULL){action=testAction;}
	const char* this_keyInput = key_output->value();
	if(this_keyInput!=NULL){keyInput=this_keyInput;}
	const char* this_mod = mod_output->value();
	if(this_mod!=NULL){mod=this_mod;}
	const char* secondarymod=mod2_output->value();
	if(secondarymod!=NULL){mod+=secondarymod;}
	const char* tertiary=mod3_output->value();
	if(tertiary!=NULL){mod+=tertiary;}
	if(action.compare("")==0){
		debug_out("No action chosen...");
		return false;
	}
	if(!emptyString(keyInput)){
		if(!emptyString(mod)){addKey(mod,keyInput,action);}
		else{addKey(keyInput,action);}
		o->clear();
		getKeys(o);
		o->redraw();
		return true;
	}
	return false;
}
bool JWM_Keyboard::Configure(Fl_Browser *key_browser,
	Fl_Input *action_name1,
	Fl_Output *current_shortcut,
	Fl_Output *mod1_output,
	Fl_Output *mod2_output,
	Fl_Output *mod3_output,
	Fl_Output *old_value)
{
	debug_out("bool Configure(Fl_Browser *key_browser,Fl_Input *action_name1,Fl_Output *current_shortcut,Fl_Output *mod1_output,Fl_Output *mod2_output,Fl_Output *mod3_output,Fl_Output *old_value)");
	const char* mykey = key_browser->text(key_browser->value());
	if(mykey==NULL)
	{
		debug_out("Configure keyshortcut empty");
		return false;
	}
	std::string keyShortcut = mykey;
	if(!emptyString(keyShortcut)){
		debug_out("Configure line="+keyShortcut);
		std::string mod1,mod2,mod3,key,program;
		mod1=getMod1(keyShortcut);
		if(!emptyString(mod1)){mod1_output->value(mod1.c_str());}
		mod2=getMod2(keyShortcut);
		if(!emptyString(mod2)){mod2_output->value(mod2.c_str());}
		mod3=getMod3(keyShortcut);
		if(!emptyString(mod3)){mod3_output->value(mod3.c_str());}
		key=getKey(keyShortcut);
		program=getAction(keyShortcut);
		action_name1->value(program.c_str());
		current_shortcut->value(key.c_str());
		old_value->value(program.c_str());
		getKeys(key_browser);
		return true;
	}
	else{fl_message("Please click on an item to configure!");}
	return false;
}
bool JWM_Keyboard::Configure_CB(Fl_Output* mod1_output, Fl_Output* mod2_output,Fl_Output* mod3_output, Fl_Input * keyshortcut,Fl_Input * action_name1,std::string CURRENT){
	debug_out("void Configure_CB(Fl_Output* mod1_output, Fl_Output* mod2_output,Fl_Output* mod3_output, Fl_Input * keyshortcut,Fl_Input * action_name1,std::string "+CURRENT+")");
	std::string MOD1,MOD2,MOD3,KEY,ACTION;
	MOD1=getOUTPUT(mod1_output);
	MOD2=getOUTPUT(mod2_output);
	MOD3=getOUTPUT(mod3_output);
	KEY=getINPUT(keyshortcut);
	ACTION=getINPUT(action_name1);
	if(emptyString(ACTION))
	{
		debug_out("No action chosen");
		return false;
	}
	if(emptyString(CURRENT))
	{
		debug_out("CURRENT is empty");
		return false;
	}
	if(!configureKey(CURRENT,MOD1,MOD2,MOD3,KEY,ACTION)){return false;}
	return saveChanges();
}
bool JWM_Keyboard::emptyString(std::string s)
{
	if ( (s.compare("")==0) || (s.compare("")==0) )
	  return true;
	return false;
}
bool JWM_Keyboard::getKeys(Fl_Browser* o){
	populateFLBrowser2Attr(o,"Key","key","mask");
	return false;
}
bool JWM_Keyboard::newpanel(){
	debug_out("bool newpanel()");
	if(newStyle() == -1){return false;}
	return true;
}
