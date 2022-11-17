## Variables in the configure (*.in) files
#####################################################################################

## DEFAULT PROGRAMS
set(JSM "jwm-settings-manager")
set (SYS_MONITOR "exec:xterm htop")
set (SCREEN_SHOT "exec:screenie")
set (RUN_DIALOG "exec:zrun")
set (CALC_PROG "exec:xcalc")
set (TERM_PROG "exec:xterm")
set (VOL_UP "exec:amixer Master 5%+")
set (VOL_DOWN "exec:amixer Master 5%-")
set (VOL_MUTE "exec:amixer Master toggle")
set (RESTART_PROGRAM "systemctl reboot")

## menu programs
set(PLACES_ROOT "exec:pcmanfm")
set(APPMENU_FILE "exec:xdgmenumaker -n -i -f jwm")
set(JWM_MENU "exec:xdgmenumaker -n -i -f jwm")

##Startup commands
set (STARTUP "<StartupCommand>nm-applet</StartupCommand>
	<StartupCommand>/usr/libexec/lxpolkit</StartupCommand>
	<StartupCommand>retrovol -hide</StartupCommand>
	<StartupCommand>synclient MaxTapTime=0</StartupCommand>")

## Desktop Background
set(BG "/usr/share/backgrounds/UHU/uhu_linux_ubk.jpg")

################### MENUS ###############################

###MENUS
# 1 nothing
# 23 mouse menu
# 5 apps
# 7 places
# 8 gnome system
# 9 shutdown
# c clock
# p panel edit
# m menu edit

## CLOCK
set(CLOCK_FORMAT "%b, %e %a %l:%M %p")
set(CLOCK "root:c")
set(OLD_CLOCK_TAG "<Clock format=\"${CLOCK_FORMAT}\"></Clock>")
set(CLOCK_TAG "<Clock format=\"${CLOCK_FORMAT}\">${CLOCK}</Clock>")

## Panel Edit
set(EDIT_PANEL_ROOT "root:p")
set(EDIT_PANEL "    <RootMenu onroot=\"p\">
	<Program icon=\"jsm-panel\" label=\"Edit Panel\">${JSM} --panel</Program>
	<Program icon=\"add\" label=\"Add new items\">${JSM} --shortcuts</Program>
    </RootMenu>")

## Menu Edit
set(EDIT_MENU_ROOT "root:m")
set(EDIT_MENU "    <RootMenu onroot=\"m\">
	<Program icon=\"reload\" label=\"Update Menus\">update-menus</Program>
	<Program icon=\"jsm-panel\" label=\"Edit Menu\">${JSM} --menu</Program>
	<Program icon=\"jsm-panel\" label=\"Edit Panel\">${JSM} --panel</Program>
    </RootMenu>")
## SHUTDOWN MENU
set(SHUTDOWN_ROOT "root:9")
set(SHUTDOWN_NAME "Kikapcsolás")
set(SHUTDOWN_ICON "process-stop")
set(SHUTDOWN_PROGRAM "systemctl poweroff")
set(LOGOUT_ICON "application-exit")
set(RESTART_ICON "view-refresh")

set(SHUTERDOWN "<Separator/>
	<Restart label=\"JWM újraindítás\" icon=\"${RESTART_ICON}\"/>
	<Exit icon=\"${LOGOUT_ICON}\" label=\"Kilépés\" confirm=\"true\" />
	<Program label=\"Gép újraindítás\" icon=\"${RESTART_ICON}\">systemctl reboot</Program>
	<Program icon=\"${SHUTDOWN_ICON}\" label=\"${SHUTDOWN_NAME}\">${SHUTDOWN_PROGRAM}</Program>")
## MAIN MENU
set(JWM_ROOT_NUM "2")
set(JWM_ROOT "root:${JWM_ROOT_NUM}")

set(MENU_ICON "uhu-32x32.png")
#MAIN MENU GENERATOR

set(JWM_ROOT_MENU "<RootMenu onroot=\"${JWM_ROOT_NUM}\">
        <Include>${JWM_MENU}</Include>
        ${SHUTERDOWN}
    </RootMenu>")
set(TORI_ROOT "${JWM_ROOT}")



set(PLACES_NAME "Saját mappa")
set(PLACES_ICON "folder")
set(MENUS_LIST_NEW "${JWM_ROOT_MENU}")
set(REGULAR_MENUS_LIST "${MENUS_LIST_NEW}")
set (ROOT_MENU "root:${JWM_ROOT_NUM}")
## Mouse MENU
set(MOUSE_MENU "<RootMenu height=\"0\" onroot=\"3\">
		<Restart icon=\"view-refresh\" label=\"JWM újraindítása\" />
		<Program icon=\"jwm-settings-manager\" label=\"JWM beállítások\">jwm-settings-manager</Program>
		<Program icon=\"jsm-desktop\" label=\"Háttér beállítás\">jwm-settings-manager --desktop</Program>
		<Program icon=\"jsm-fonts\" label=\"Betűválasztás\">jwm-settings-manager --font</Program>
		<Program icon=\"jsm-windows\" label=\"Ablak beállítások\">jwm-settings-manager --window</Program>
		<Program icon=\"jsm-panel\" label=\"Panel szerkesztés\">jwm-settings-manager --panel</Program>
		<Program icon=\"list-add\" label=\"Új elem\">jwm-settings-manager --shortcuts</Program>
		<Program icon=\"jsm-panel\" label=\"Menüszerkesztés\">jwm-settings-manager --menu</Program>
		<Program icon=\"jsm-theme\" label=\"Témák\">jwm-settings-manager --themes</Program>
		<Kill icon=\"process-stop\" label=\"Ablak kilövés\" />
	</RootMenu>")
## window corners override in individual files
set(CORNER "4")
set(W_HEIGHT "20")
## PANEL CONFIGURATIONS
## THE NORMAL CONFIG used in Default, Ambiance and Live
set (DEFAULT_TRAY "    <Tray x=\"0\" y=\"-1\" height=\"34\" valign=\"top\" width=\"0\" halign=\"fixed\" layout=\"horizontal\">
        <TrayButton icon=\"${MENU_ICON}\" border=\"false\" popup=\"Programok\">
            <Button mask=\"1\">${JWM_ROOT}</Button>
            <Button mask=\"23\">${EDIT_MENU_ROOT}</Button>
        </TrayButton>
		<Spacer width=\"2\" />
        <TrayButton popup=\"JWM beállítások\" icon=\"jwm-settings-manager\" border=\"false\">
            <Button mask=\"1\">root:3</Button>
        </TrayButton>
		<Spacer width=\"2\" />
        <TrayButton popup=\"${PLACES_NAME}\" icon=\"${PLACES_ICON}\" border=\"false\">
            <Button mask=\"1\">${PLACES_ROOT}</Button>
        </TrayButton>
		<Spacer width=\"2\" />
        <Pager labeled=\"true\"/>
        <TaskList maxwidth=\"256\"/>
        <Dock/>
        <Swallow name=\"xload\" width=\"64\">xload -nolabel -bg DimGrey -fg Grey -hl DarkGrey</Swallow>
        ${CLOCK_TAG}
        <TrayButton popup=\"${SHUTDOWN_NAME}\" icon=\"application-exit\" border=\"false\">${SHUTDOWN_ROOT}</TrayButton>
    </Tray>")
### OLD STYLE 2.2.2 configs
set (OLD_DEFAULT_TRAY "    <Tray x=\"0\" y=\"-1\" height=\"34\" valign=\"top\" width=\"0\" halign=\"fixed\" layout=\"horizontal\">
        <TrayButton icon=\"${MENU_ICON}\" border=\"false\" popup=\"Programok\">${TORI_ROOT}</TrayButton>
        <TrayButton popup=\"${PLACES_NAME}\" icon=\"${PLACES_ICON}\" border=\"false\">${PLACES_ROOT}</TrayButton>
        <Pager labeled=\"true\"/>
        <TaskList maxwidth=\"256\"/>
        <Dock/>
        <Swallow name=\"xload\" width=\"64\">xload -nolabel -bg DimGrey -fg Grey -hl DarkGrey</Swallow>
        ${OLD_CLOCK_TAG}
        <TrayButton popup=\"${SHUTDOWN_NAME}\" icon=\"application-exit\" border=\"false\">${SHUTDOWN_ROOT}</TrayButton>
    </Tray>")

## 'GNOME' MENUS
set(GNOME_MENUS_LIST "<!-- NOTE, if you hand edit this root:5 is the app menu and root:7 is the places menu  you have been duly warned :) root:9 is the system menu -->
    <Include>$HOME/.config/gnomeapps</Include>
    <Include>$HOME/.config/gnomesystem</Include>")
set (GNOME_SYS_ROOT "root:8")
set (GNOME_SYS_NAME "System")
set (GNOME_SYS_ICON "applications-system")

## GNOME TRAYS ############
set (SHOW_DESK_ICON "preferences-system-hotcorners.png")
set (GNOME_TRAY "    <Tray height=\"34\" autohide=\"false\" valign=\"top\" width=\"0\" halign=\"fixed\" layout=\"horizontal\">
        <TrayButton icon=\"${MENU_ICON}\" border=\"false\" popup=\"Programok\">${TORI_ROOT}</TrayButton>
        <TrayButton label=\"${GNOME_SYS_NAME}\" icon=\"${GNOME_SYS_ICON}\" border=\"false\">${GNOME_SYS_ROOT}</TrayButton>
        <TrayButton popup=\"${PLACES_NAME}\" icon=\"${PLACES_ICON}\" border=\"false\">${PLACES_ROOT}</TrayButton>
        <Spacer/>
        <Dock/>
         ${CLOCK_TAG}
        <TrayButton popup=\"${SHUTDOWN_NAME}\" icon=\"application-exit\" border=\"false\">${SHUTDOWN_ROOT}</TrayButton>
    </Tray>
    <Tray x=\"0\" y=\"-1\" height=\"34\" autohide=\"false\" valign=\"bottom\" width=\"0\" halign=\"fixed\" layout=\"horizontal\">
	<TrayButton icon=\"${SHOW_DESK_ICON}\" border=\"false\">showdesktop</TrayButton>
        <TaskList maxwidth=\"256\"/>
        <Pager labeled=\"false\"/>
    </Tray>")
set (OLD_GNOME_TRAY "    <Tray height=\"34\" autohide=\"false\" valign=\"top\" width=\"0\" halign=\"fixed\" layout=\"horizontal\">
        <TrayButton icon=\"${MENU_ICON}\" border=\"false\" popup=\"Programok\">${TORI_ROOT}</TrayButton>
        <TrayButton label=\"${GNOME_SYS_NAME}\" icon=\"${GNOME_SYS_ICON}\" border=\"false\">${GNOME_SYS_ROOT}</TrayButton>
        <TrayButton popup=\"${PLACES_NAME}\" icon=\"${PLACES_ICON}\" border=\"false\">${PLACES_ROOT}</TrayButton>
        <Spacer/>
        <Dock/>
         ${OLD_CLOCK_TAG}
        <TrayButton popup=\"${SHUTDOWN_NAME}\" icon=\"application-exit\" border=\"false\">${SHUTDOWN_ROOT}</TrayButton>
    </Tray>
    <Tray x=\"0\" y=\"-1\" height=\"34\" autohide=\"false\" valign=\"bottom\" width=\"0\" halign=\"fixed\" layout=\"horizontal\">
	<TrayButton icon=\"${SHOW_DESK_ICON}\" border=\"false\">showdesktop</TrayButton>
        <TaskList maxwidth=\"256\"/>
        <Pager labeled=\"false\"/>
    </Tray>")

set(LIVE_MENUS_LIST "<!-- NOTE, if you hand edit this root:5 is the app menu and root:7 is the places menu  you have been duly warned :) -->
${EDIT_MENU}
${EDIT_PANEL}
${JWM_ROOT_MENU}
    <RootMenu onroot=\"1\"/>
    <!-- Main Menu -->
    <Include>${APPMENU_FILE}</Include>
    <!--Shudown Menu-->
    <RootMenu height=\"0\" onroot=\"9\">
        <Program icon=\"${SHUTDOWN_ICON}\" label=\"Kikapcsolás\">${SHUTDOWN_PROGRAM}</Program>
        <Program icon=\"${RESTART_ICON}\" label=\"Újraindítás\">${RESTART_PROGRAM}</Program>
        <Restart label=\"JWM újraindítás\" icon=\"${RESTART_ICON}\"/>
    </RootMenu>
    <!-- Mouse Menu-->
    <RootMenu height=\"16\" onroot=\"2\">
        <Program icon=\"folder-home\" label=\"Home\">xdg-open ~/</Program>
        <Program icon=\"jwm-settings-manager\" label=\"Settings\">jwm-settings-manager</Program>
        <Program icon=\"preferences-desktop-wallpaper\" label=\"Change Desktop Background\">jwm-settings-manager --desktop</Program>
    </RootMenu>")

set(FONT "Sans:10")
## see http://en.wikipedia.org/wiki/Table_of_keyboard_shortcuts
# I tried to implement everything from GNOME, Windows and OSX in here
set(KEYSHORTCUTS "<Key key=\"Up\">up</Key>
    <Key key=\"Down\">down</Key>
    <Key key=\"Right\">right</Key>
    <Key key=\"Left\">left</Key>
    <Key key=\"a\">left</Key>
    <Key key=\"s\">down</Key>
    <Key key=\"w\">up</Key>
    <Key key=\"d\">right</Key>
    <Key key=\"Return\">select</Key>
    <Key key=\"Escape\">escape</Key>
    <Key key=\"XF86Search\">exec:${SEARCH_PROG}</Key>
    <Key key=\"XF86Explorer\">exec:xdg-open $HOME</Key>
    <Key key=\"XF86PowerOff\">exec:${SHUTDOWN_PROGRAM}</Key>
    <Key key=\"XF86AudioMute\">${VOL_MUTE}</Key>
    <Key key=\"XF86AudioRaiseVolume\">${VOL_UP}</Key>
    <Key key=\"XF86AudioLowerVolume\">${VOL_DOWN}</Key>
    <Key key=\"XF86Calculator\">${CALC_PROG}</Key>
    <Key key=\"Print\">${SCREEN_SHOT}</Key>
    <Key mask=\"CA\" key=\"p\">${SCREEN_SHOT}</Key>
    <Key mask=\"S4\" key=\"3\">${SCREEN_SHOT}</Key>
    <Key mask=\"CA\" key=\"t\">${TERM_PROG}</Key>
    <Key mask=\"CS\" key=\"Escape\">${SYS_MONITOR}</Key>
    <Key mask=\"A4\" key=\"Escape\">${SYS_MONITOR}</Key>
    <Key mask=\"CA\" key=\"Delete\">${SYS_MONITOR}</Key>
    <Key mask=\"C\" key=\"Escape\">${SYS_MONITOR}</Key>
    <Key mask=\"A\" key=\"Tab\">next</Key>
    <Key mask=\"4\" key=\"Tab\">next</Key>
    <Key mask=\"AS\" key=\"Tab\">nextstacked</Key>
    <Key mask=\"S4\" key=\"Tab\">nextstacked</Key>
    <Key mask=\"SA\" key=\"Tab\">nextstacked</Key>
    <Key mask=\"CA\" key=\"Tab\">nextstacked</Key>
    <Key mask=\"C\" key=\"#\">desktop#</Key>
    <Key mask=\"C\" key=\"Escape\">${ROOT_MENU}</Key>
    <Key mask=\"A\" key=\"F2\">${RUN_DIALOG}</Key>
    <Key mask=\"4\" key=\"F2\">${RUN_DIALOG}</Key>
    <Key mask=\"4\" key=\"space\">${RUN_DIALOG}</Key>
    <Key mask=\"CA\" key=\"Right\">rdesktop</Key>
    <Key mask=\"CA\" key=\"Left\">ldesktop</Key>
    <Key mask=\"CA\" key=\"Up\">udesktop</Key>
    <Key mask=\"CA\" key=\"Down\">ddesktop</Key>
    <Key mask=\"A\" key=\"space\">window</Key>
    <Key mask=\"A\" key=\"F3\">window</Key>
    <Key key=\"F11\">fullscreen</Key>
    <Key mask=\"C\" key=\"F11\">fullscreen</Key>
    <Key mask=\"CS\" key=\"f\">fullscreen</Key>
    <Key mask=\"4C\" key=\"f\">fullscreen</Key>
    <Key mask=\"A\" key=\"F12\">shade</Key>
    <Key mask=\"SC4\" key=\"Up\">maximize</Key>
    <Key mask=\"4\" key=\"L\">maximize</Key>
    <Key mask=\"A\" key=\"F10\">maximize</Key>
    <Key mask=\"4\" key=\"Down\">minimize</Key>
    <Key mask=\"4\" key=\"m\">minimize</Key>
    <Key mask=\"A\" key=\"F9\">minimize</Key>
    <Key mask=\"4\" key=\"w\">close</Key>
    <Key mask=\"A\" key=\"F4\">close</Key>")
set(NEW_KEYSHORTCUTS "${KEYSHORTCUTS}
    <Key mask=\"C4\" key=\"Up\">maxtop</Key>
    <Key mask=\"C4\" key=\"Left\">maxleft</Key>
    <Key mask=\"C4\" key=\"Right\">maxright</Key>
    <Key mask=\"C4\" key=\"Down\">maxbottom</Key>
    <Key mask=\"C4\" key=\"v\">maxv</Key>
    <Key mask=\"4S\" key=\"Up\">maxv</Key>
    <Key mask=\"C4\" key=\"h\">maxh</Key>
    <Key mask=\"4\" key=\"Right\">sendr</Key>
    <Key mask=\"4\" key=\"Left\">sendl</Key>
    <Key mask=\"4\" key=\"Up\">sendu</Key>
    <Key mask=\"4\" key=\"Down\">sendd</Key>
    <Key mask=\"SCA\" key=\"Right\">sendr</Key>
    <Key mask=\"SCA\" key=\"Left\">sendl</Key>
    <Key mask=\"SCA\" key=\"Up\">sendu</Key>
    <Key mask=\"SCA\" key=\"Down\">sendd</Key>")

set(ICONS_LIST "<IconPath>/usr/share/jwm</IconPath>
	<IconPath>/usr/share/pixmaps</IconPath>
	<IconPath>/usr/share/icons/hicolor/48x48/apps</IconPath>
	<IconPath>/usr/share/icons/hicolor/scaleable/apps</IconPath>
	<IconPath>/usr/share/icons/hicolor/24x24/stock/data</IconPath>
")

set(MOUSE "<DoubleClickSpeed>400</DoubleClickSpeed>
    <DoubleClickDelta>2</DoubleClickDelta>")
set (GROUPS "<Group>
        <Option>noshade</Option>
    </Group>
    <Group>
        <Class>Pidgin</Class>
        <Option>sticky</Option>
    </Group>
    <Group>
        <Name>gkrellm</Name>
        <Option>nolist</Option>
        <Option>sticky</Option>
    </Group>
    <Group>
        <Name>conky</Name>
        <Option>nolist</Option>
        <Option>sticky</Option>
    </Group>")
set(LIVE_GROUPS "<Group>
        <Class>OBI</Class>
        <Option>noclose</Option>
        <Option>constrain</Option>
    </Group>")
set(BUTTONS "<ButtonClose>/usr/share/jwm-settings-manager/Buttons/Default/close.png</ButtonClose>
    <ButtonMax>/usr/share/jwm-settings-manager/Buttons/Default/max.png</ButtonMax>
    <ButtonMaxActive>/usr/share/jwm-settings-manager/Buttons/Default/max-toggle.png</ButtonMaxActive>
    <ButtonMin>/usr/share/jwm-settings-manager/Buttons/Default/min.png</ButtonMin>")
#####################################################################################
### End Variables

#include the cmakelists in each dir for the custom colours
add_subdirectory(Default)
add_subdirectory(Ambiance)
add_subdirectory(DarkGnome2)
add_subdirectory(LightGnome2)
add_subdirectory(Bassem)
add_subdirectory(Numix)
## add your theme below to have it automatically added to the -common.install file
# FORMAT:
# data/themes/YOUR_THEME_NAME/ usr/share/${EXEC}/themes/

set(COMMON_INSTALL "data/themes/old/ usr/share/${EXEC}/themes/
data/themes/2.3.0/ usr/share/${EXEC}/themes/
data/themes/Default/ usr/share/${EXEC}/themes/
data/themes/Ambiance/ usr/share/${EXEC}/themes/
data/themes/DarkGnome2/ usr/share/${EXEC}/themes/
data/themes/LightGnome2/ usr/share/${EXEC}/themes/
data/themes/Bassem/ usr/share/${EXEC}/themes/
data/themes/Numix/ usr/share/${EXEC}/themes/")

# configure the file
set(COMMON_FILE "../../debian/${EXEC}-common.install")
configure_file(${COMMON_FILE}.in ${COMMON_FILE})
