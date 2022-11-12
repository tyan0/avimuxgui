; CLW-Datei enth�lt Informationen f�r den MFC-Klassen-Assistenten

[General Info]
Version=1
LastClass=CVideoInformationDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "AVIMux_GUI.h"

ClassCount=36
Class1=CAVIMux_GUIApp
Class2=CAVIMux_GUIDlg
Class3=CAboutDlg

ResourceCount=29
Resource1=IDD_AVIMUX_GUI_DIALOG (Englisch (GB))
Resource2=IDR_MAINFRAME
Class4=CSplitPointsDlg
Resource3=IDD_RIFFCHUNKTREEDLG
Resource4=IDR_AUDIOSTREAMSMENU
Resource5=IDD_VIDEOINFO (Englisch (USA))
Resource6=IDD_SETOUTPUTOPTIONS
Class5=CSplitPointList
Resource7=IDD_SETDELAY_DLG (Englisch (USA))
Resource8=IDD_CHAPTERDIALOG
Class6=AddSplitPointDlg
Resource9=IDD_EBMLTREE_DLG
Class7=CAudioSourceTree
Resource10=IDD_OPENFILEOPTIONS (Englisch (USA))
Class8=CSetDelayDlg
Resource11=IDR_LANGUAGES
Resource12=IDR_VIDEOINFOMENU
Resource13=IDD_SPLITPOINTS (Englisch (USA))
Resource14=IDD_SAVEAVIOPTIONS (Englisch (USA))
Class9=CSourceFileListBox
Resource15=IDR_SOURCEFILEMENU
Class10=CVideoInformationDlg
Class11=CVideoInformationDlgListbox
Resource16=IDD_SETFLAGS
Resource17=IDD_ABOUTBOX (Englisch (USA))
Class12=CSetFramerateDlg
Resource18=IDD_ADDSPLITPOINTDLG
Class13=CSetMainAVIHeaderFlagsDlg
Resource19=IDD_SETFLAGS (Englisch (USA))
Class14=CSetOpenFileOptionsDlg
Resource20=IDD_SETFRAMERATE (Englisch (USA))
Resource21=IDD_ABOUTBOX
Resource22=IDD_ADDSPLITPOINTDLG (Englisch (USA))
Resource23=IDD_SETFRAMERATE
Resource24=IDD_AVIMUX_GUI_DIALOG (Englisch (USA))
Class15=CSetStoreFileOptionsDlg
Resource25=IDR_SPLITPOINTLISTMENU
Class16=CEnhancedListBox
Class17=CVideoSourceListBox
Class18=CSubtitlesListBox
Resource26=IDD_AVIMUX_GUI_DIALOG
Class19=CRIFFChunkTreeDlg
Resource27=IDD_VIDEOINFO
Class20=CProtocolListCtrl
Class21=CProgressList
Resource28=IDD_SPLITPOINTS
Class22=CChapterDlg
Class23=CChapterDlgTree
Class24=CUserDrawEdit
Class25=CClusterTimeEdit
Class26=CAC3FrameCountEdit
Class27=CMKVAC3FrameCountEdit
Class28=CEBMLTreeDlg
Class29=CEBMLTree
Class30=CUnicodeTreeCtrl
Class31=CChapterDlgList
Class32=CChapterSegmentUIDEdit
Class33=CVerifyEdit
Class34=CResolutionEdit
Class35=CMKVHeaderSizeEdit
Class36=CResizeableDialog
Resource29=IDR_SUBTITLEMENU

[CLS:CAVIMux_GUIApp]
Type=0
HeaderFile=AVIMux_GUI.h
ImplementationFile=AVIMux_GUI.cpp
Filter=N
LastObject=CAVIMux_GUIApp

[CLS:CAVIMux_GUIDlg]
Type=0
HeaderFile=AVIMux_GUIDlg.h
ImplementationFile=AVIMux_GUIDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=CAVIMux_GUIDlg

[CLS:CAboutDlg]
Type=0
HeaderFile=AVIMux_GUIDlg.h
ImplementationFile=AVIMux_GUIDlg.cpp
Filter=D
LastObject=CAboutDlg
BaseClass=CDialog
VirtualFilter=dWC

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=5
Control1=IDC_AUTHOR,static,1342308352
Control2=IDOK,button,1342373889
Control3=IDC_STATIC,static,1342308352
Control4=IDC_STATIC,static,1342308352
Control5=IDC_ABOUTBOX_LABEL,static,1342312449

[DLG:IDD_AVIMUX_GUI_DIALOG (Englisch (GB))]
Type=1
Class=CAVIMux_GUIDlg
ControlCount=46
Control1=IDCANCEL,button,1342242816
Control2=IDC_SOURCEFILELIST,listbox,1352728833
Control3=IDC_BUTTON1,button,1342242816
Control4=IDC_AVAILABLEAUDIOSTREAMS,listbox,1353779457
Control5=IDC_STATIC,static,1342308352
Control6=IDC_AVAILABLEVIDEOSTREAMS,listbox,1353777411
Control7=IDC_STATIC,static,1342308352
Control8=IDC_STATIC,static,1342308352
Control9=IDC_RECLISTS,button,1342242819
Control10=IDC_STATIC,static,1342308352
Control11=IDC_STATIC,button,1342308359
Control12=IDC_AUDIOINTERLEAVE,edit,1350639744
Control13=IDC_STATIC,static,1342308352
Control14=IDC_PRELOAD,edit,1350631552
Control15=IDC_STATIC,static,1342308352
Control16=IDC_MAXFILESIZE,edit,1350631552
Control17=IDC_RADIO_FRAMES,{8BD21D50-EC42-11CE-9E0D-00AA006002F3},1342242816
Control18=IDC_RADIO_SECONDS,{8BD21D50-EC42-11CE-9E0D-00AA006002F3},1342242816
Control19=IDC_RADIO_MBYTE,{8BD21D50-EC42-11CE-9E0D-00AA006002F3},1342242816
Control20=IDC_START,button,1342242816
Control21=IDC_STOP,button,1476460544
Control22=IDC_STATIC,button,1342177287
Control23=IDC_PROGBAR,{35053A22-8589-11D1-B16A-00C0F0283628},1342177280
Control24=IDC_STATIC,static,1342308352
Control25=IDC_FORMAT,edit,1350631552
Control26=IDC_STATIC,static,1342308352
Control27=IDC_DESTFILE,edit,1350633600
Control28=IDC_STATIC,static,1342308352
Control29=IDC_FRAMES,edit,1350633600
Control30=IDC_STATIC,static,1342308352
Control31=IDC_STATIC,static,1342308352
Control32=IDC_STATIC,static,1342308352
Control33=IDC_STATIC,static,1342308352
Control34=IDC_STATIC,static,1342308352
Control35=IDC_STATIC,static,1342308352
Control36=IDC_CURR_VIDEO,edit,1350633602
Control37=IDC_CURR_AUDIO,edit,1350633602
Control38=IDC_STATIC,static,1342308352
Control39=IDC_CURR_OVERHEAD,edit,1350633602
Control40=IDC_CURR_TOTAL,edit,1350633602
Control41=IDC_TOTAL_VIDEO,edit,1350633602
Control42=IDC_TOTAL_AUDIO,edit,1350633602
Control43=IDC_TOTAL_OVERHEAD,edit,1350633602
Control44=IDC_TOTAL_TOTAL,edit,1350633602
Control45=IDC_STATIC,static,1342308352
Control46=IDC_MAXFRAMES,edit,1350631552

[DLG:IDD_AVIMUX_GUI_DIALOG (Englisch (USA))]
Type=1
Class=CAVIMux_GUIDlg
ControlCount=54
Control1=IDCANCEL,button,1342242816
Control2=IDC_AVAILABLEAUDIOSTREAMS,listbox,1353779457
Control3=IDC_STATIC,static,1342308352
Control4=IDC_AVAILABLEVIDEOSTREAMS,listbox,1353777411
Control5=IDC_STATIC,static,1342308352
Control6=IDC_STATIC,static,1342308352
Control7=IDC_START,button,1342242816
Control8=IDC_STOP,button,1476460544
Control9=IDC_STATIC,button,1342177287
Control10=IDC_STATIC,static,1342308352
Control11=IDC_DESTFILE,edit,1350633600
Control12=IDC_STATIC,static,1342308352
Control13=IDC_FRAMES,edit,1350633600
Control14=IDC_STATIC,static,1342308352
Control15=IDC_STATIC,static,1342308352
Control16=IDC_STATIC,static,1342308352
Control17=IDC_STATIC,static,1342308352
Control18=IDC_STATIC,static,1342308352
Control19=IDC_STATIC,static,1342308352
Control20=IDC_CURR_VIDEO,edit,1350633602
Control21=IDC_CURR_AUDIO,edit,1350633602
Control22=IDC_STATIC,static,1342308352
Control23=IDC_CURR_OVERHEAD,edit,1350633602
Control24=IDC_CURR_TOTAL,edit,1350633602
Control25=IDC_TOTAL_VIDEO,edit,1350633602
Control26=IDC_TOTAL_AUDIO,edit,1350633602
Control27=IDC_TOTAL_OVERHEAD,edit,1350633602
Control28=IDC_TOTAL_TOTAL,edit,1350633602
Control29=IDC_ADDAVILIST,button,1342242816
Control30=IDL_SOURCEFILELIST,listbox,1352730881
Control31=IDC_PROGBAR,msctls_progress32,1350565889
Control32=IDC_STATIC,static,1342308352
Control33=IDC_TRANSFERRATE,edit,1350633600
Control34=IDC_AVOIDSEEKOPS,button,1342242819
Control35=IDC_SAVE,button,1342242816
Control36=IDC_STATIC,static,1342308352
Control37=IDC_FPS,edit,1350633600
Control38=IDC_STATIC,static,1342308352
Control39=IDC_LEGACYPROGRESS,msctls_progress32,1350565888
Control40=IDC_STATIC,static,1342308352
Control41=IDC_STATIC,static,1342308352
Control42=IDC_OUTPUTOPTIONS,button,1342242816
Control43=IDC_NO_AUDIO,button,1342242819
Control44=IDC_PROTOCOL,listbox,1353781505
Control45=IDC_STATIC,static,1342308352
Control46=IDC_ALL_AUDIO,button,1342242819
Control47=IDC_AVAILABLETEXTSTREAMS,listbox,1352730881
Control48=IDC_STATIC,static,1342308352
Control49=IDC_NO_SUBTITLES,button,1342242819
Control50=IDC_ALL_SUBTITLES,button,1342242819
Control51=IDC_DEFAULT_AUDIO,button,1342242819
Control52=IDC_DEFAULT_AUDIO_NUMBER,edit,1350631552
Control53=IDC_SUBNAME,edit,1350631552
Control54=IDC_STATIC,static,1342308352

[DLG:IDD_AVIMUX_GUI_DIALOG]
Type=1
Class=CAVIMux_GUIDlg
ControlCount=44
Control1=IDCANCEL,button,1342177280
Control2=IDC_AVAILABLEAUDIOSTREAMS,listbox,1085278465
Control3=IDS_MAIN_AUDIO,static,1342308352
Control4=IDC_START,button,1342177280
Control5=IDC_STOP,button,1342242816
Control6=IDS_MAIN_PROGRESS,button,1342177287
Control7=IDS_MAIN_PRG_DESTFILE,static,1342308352
Control8=IDC_DESTFILE,edit,1350568064
Control9=IDS_MAIN_PRG_FRAMES,static,1342308352
Control10=IDC_FRAMES,edit,1350568064
Control11=IDC_ADDAVILIST,button,1342177280
Control12=IDC_SOURCEFILELIST,listbox,1352665361
Control13=IDS_MAIN_PRG_PROGRESS,static,1342308352
Control14=IDC_LEGACYPROGRESS,msctls_progress32,1350565888
Control15=IDS_MAIN_PRG_LEGIDX,static,1342308352
Control16=IDS_MAIN_OPENFILES,static,1342308364
Control17=IDC_NO_AUDIO,button,1342177283
Control18=IDC_OUTPUTOPTIONS,button,1342193665
Control19=IDS_MAIN_PROTOCOL,static,1342308352
Control20=IDC_ALL_AUDIO,button,1342177283
Control21=IDC_AVAILABLETEXTSTREAMS,listbox,1084229889
Control22=IDS_MAIN_SUBTITLES,static,1342308352
Control23=IDC_NO_SUBTITLES,button,1342177283
Control24=IDC_ALL_SUBTITLES,button,1342177283
Control25=IDC_DEFAULT_AUDIO,button,1342177283
Control26=IDC_DEFAULT_AUDIO_NUMBER,edit,1350631552
Control27=IDC_AUDIONAME,edit,1350631552
Control28=IDS_MAIN_AUDIODELAY,static,1342308352
Control29=IDC_ENHLIST,SysListView32,1082132481
Control30=IDC_PROGRESS_LIST,SysListView32,1350600705
Control31=IDC_PROTOCOL,SysListView32,1350565889
Control32=IDC_PROGCTRL,msctls_progress32,1350565889
Control33=IDC_VIDEOSTRETCHFACTOR,edit,1082130560
Control34=IDC_VIDEOSTRETCHFACTORLABEL,static,1073872896
Control35=IDC_TITLE,edit,1350566016
Control36=IDC_TITLELABEL,static,1342308352
Control37=IDC_AUDIOTREE,SysTreeView32,1350635823
Control38=IDC_OUTPUTRESOLUTION_LABEL,static,1342308354
Control39=IDC_OUTPUTRESOLUTION,edit,1350566016
Control40=IDC_STREAM_LNG,combobox,1344339970
Control41=IDC_DELAY,edit,1350631552
Control42=IDC_STATUSLINE,edit,1484785792
Control43=IDS_MAIN_AUDIONAME,static,1342308352
Control44=IDC_CHAPTER_EDITOR,button,1342177280

[MNU:IDR_SOURCEFILEMENU]
Type=1
Class=?
Command1=IDM_ADDAVILIST
Command2=IDM_ADDFILE
Command3=IDM_BUILDRIFFSTATE
Command4=IDM_BYTEACCURACY
Command5=IDM_CLEARALL
Command6=IDM_CLEARALL_NC
Command7=IDM_CONFIGSOURCES
Command8=IDM_DESELAUDIO
Command9=IDM_DESELFILE
Command10=IDM_DESELSUB
Command11=IDM_DISPDONEDLG
Command12=IDM_DISPLAYAUDIODELAY
Command13=IDM_DISPLAYAUDIONAME
Command14=IDM_DISPLAYSUBNAME
Command15=IDM_DISPOVWRTDLG
Command16=IDM_DOADDFILE
Command17=IDM_EXITAFTERWARDS
Command18=IDM_EXTRACTM2F2
Command19=IDM_GETNEWSUBNAME
Command20=IDM_M2F2CRC
Command21=IDM_OPENADVANCEDOPTIONS
Command22=IDM_PROTOCOL
Command23=IDM_REMOVE
Command24=IDM_SAVECONFIG
Command25=IDM_SAVEPROTOCOLAS
Command26=IDM_SELAUDIO
Command27=IDM_SELFILE
Command28=IDM_SETLANGUAGE
Command29=IDM_SETOPTION
Command30=IDM_SETOUTPUTOPTIONS
Command31=IDM_SETINPUTOPTIONS
Command32=IDM_SELSUB
Command33=IDM_STARTMUXING
Command34=IDM_VIDEOINFORMATION
Command35=IDM_CHANGESBR
Command36=IDM_SETDEFAULTTRACK
Command37=IDM_SETACTIVESEGMENT
Command38=IDM_SETACTIVESEGMENT2
Command39=IDM_SETACTIVESEGMENT3
Command40=IDM_SETACTIVESEGMENT4
Command41=IDM_SETACTIVESEGMENT5
Command42=IDM_SETACTIVESEGMENT6
Command43=IDM_SETACTIVESEGMENT7
Command44=IDM_SETACTIVESEGMENT8
Command45=IDM_SETACTIVESEGMENT9
Command46=IDM_SETACTIVESEGMENT10
Command47=IDM_SETACTIVESEGMENT11
Command48=IDM_SETACTIVESEGMENT12
Command49=IDM_SETACTIVESEGMENT13
Command50=IDM_SETACTIVESEGMENT14
Command51=IDM_SETACTIVESEGMENT15
Command52=IDM_SETACTIVESEGMENT16
Command53=IDM_IMMED_ADD_AUDIO
Command54=IDM_ENABLECHAPTER
Command55=IDM_HIDECHAPTER
Command56=IDM_ORDEREDEDITION
Command57=IDM_DEFAULTEDITION
Command58=IDM_CHAPTER_COPY
Command59=IDM_CHAPTER_PASTE_AS_CHILD
Command60=IDM_CHAPTER_PASTE_AFTER
Command61=IDM_CHAPTER_DELETE_CLIPBOARD
Command62=IDM_CHAPTER_PASTE_INTO_NEW_EDITION
Command63=IDM_CHAPTER_PASTE_EACH_INTO_EDITION
Command64=IDM_CHAPTER_REINIT_UID_32
Command65=IDM_CHAPTER_REINIT_UID_64
Command66=IDM_CHAPTER_COPY_CHILDREN
Command67=IDM_CHAPTER_NUMERATE
Command68=IDM_EDITION_TO_CHAPTER
Command69=IDM_SELVIDEO
CommandCount=69

[DLG:IDD_SPLITPOINTS]
Type=1
Class=CSplitPointsDlg
ControlCount=9
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_SPLITPOINTLIST,listbox,1352728833
Control4=IDC_ESPLITPOINT,edit,1350631552
Control5=IDC_ADD,button,1342242817
Control6=IDC_DELETE,button,1342242816
Control7=IDC_STATIC,static,1342308352
Control8=IDC_STATIC,static,1342308352
Control9=IDC_STATIC,static,1342308352

[CLS:CSplitPointsDlg]
Type=0
HeaderFile=SplitPointsDlg.h
ImplementationFile=SplitPointsDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_SPLITPOINTLIST
VirtualFilter=dWC

[CLS:CSplitPointList]
Type=0
HeaderFile=SplitPointList.h
ImplementationFile=SplitPointList.cpp
BaseClass=CListBox
Filter=W
VirtualFilter=bWC
LastObject=CSplitPointList

[MNU:IDR_SPLITPOINTLISTMENU]
Type=1
Class=?
Command1=IDM_ADDSPLITPOINT
Command2=IDM_REMOVESPLITPOINT
Command3=IDM_CHANGESPLITPOINT
CommandCount=3

[DLG:IDD_ADDSPLITPOINTDLG]
Type=1
Class=AddSplitPointDlg
ControlCount=4
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_NEWSPLITPOINT,edit,1350639744
Control4=IDC_ASP_NEWPART,static,1342308352

[CLS:AddSplitPointDlg]
Type=0
HeaderFile=AddSplitPointDlg.h
ImplementationFile=AddSplitPointDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=AddSplitPointDlg
VirtualFilter=dWC

[MNU:IDR_AUDIOSTREAMSMENU]
Type=1
Class=?
Command1=IDM_SETDELAY
Command2=IDM_EXTRACTMP3
Command3=IDM_EXTRACTWAV
Command4=IDM_EXTRACTAC3
Command5=IDM_EXTRACTDTS
Command6=IDM_EXTRACT_BINARY
Command7=IDM_EXTRACT_SUB2TEXT
Command8=IDM_EXTRACT_TOADTS
Command9=IDM_EXTRACT_OGGVORBIS
CommandCount=9

[CLS:CSetDelayDlg]
Type=0
HeaderFile=SetDelayDlg.h
ImplementationFile=SetDelayDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=CSetDelayDlg
VirtualFilter=dWC

[DLG:IDD_ABOUTBOX (Englisch (USA))]
Type=1
Class=CAboutDlg
ControlCount=5
Control1=IDC_STATIC,static,1342308480
Control2=IDC_STATIC,static,1342308352
Control3=IDOK,button,1342373889
Control4=IDC_STATIC,static,1342308352
Control5=IDC_STATIC,static,1342308352

[DLG:IDD_SPLITPOINTS (Englisch (USA))]
Type=1
Class=CSplitPointsDlg
ControlCount=3
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_SPLITPOINTLIST,listbox,1352728833

[DLG:IDD_ADDSPLITPOINTDLG (Englisch (USA))]
Type=1
Class=AddSplitPointDlg
ControlCount=4
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_NEWSPLITPOINT,edit,1350639744
Control4=IDC_STATIC,static,1342308352

[DLG:IDD_SETDELAY_DLG (Englisch (USA))]
Type=1
Class=CSetDelayDlg
ControlCount=4
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_DELAY,edit,1350631552
Control4=IDC_STATIC,static,1342308352

[CLS:CSourceFileListBox]
Type=0
HeaderFile=SourceFileListBox.h
ImplementationFile=SourceFileListBox.cpp
BaseClass=CEnhancedListBox
Filter=W
LastObject=CSourceFileListBox
VirtualFilter=bWC

[DLG:IDD_VIDEOINFO]
Type=1
Class=CVideoInformationDlg
ControlCount=6
Control1=IDOK,button,1342242817
Control2=IDE_VIDEOINFORMATION,listbox,1352728833
Control3=IDC_APPLYREPAIRS,button,1342242816
Control4=IDC_BUTTON1,button,1342242816
Control5=IDC_TREE1,SysTreeView32,1350631431
Control6=IDC_SAVETREE,button,1342242816

[CLS:CVideoInformationDlg]
Type=0
HeaderFile=VideoInformationDlg.h
ImplementationFile=VideoInformationDlg.cpp
BaseClass=CResizeableDialog
Filter=D
LastObject=IDC_TREE1
VirtualFilter=dWC

[CLS:CVideoInformationDlgListbox]
Type=0
HeaderFile=VideoInformationDlgListbox.h
ImplementationFile=VideoInformationDlgListbox.cpp
BaseClass=CListBox
Filter=W
VirtualFilter=bWC
LastObject=CVideoInformationDlgListbox

[MNU:IDR_VIDEOINFOMENU]
Type=1
Class=?
Command1=IDM_VILB_REPAIRODML
Command2=IDM_VILB_REPAIRFRAMERATE
Command3=IDM_VILB_SETFRAMERATE
Command4=IDM_VILB_SETMAHFLAGS
Command5=IDM_VILB_SAVEAS
Command6=IDM_VILB_TOTALFRAMES
CommandCount=6

[DLG:IDD_SETFRAMERATE]
Type=1
Class=CSetFramerateDlg
ControlCount=7
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_NEWFRAMERATE,edit,1350631552
Control4=IDC_SFR_UNIT,button,1342177287
Control5=IDR_FR_FPS,button,1342177289
Control6=IDR_FR_MSPF,button,1342177289
Control7=IDR_FR_NSPF,button,1342177289

[CLS:CSetFramerateDlg]
Type=0
HeaderFile=SetFramerateDlg.h
ImplementationFile=SetFramerateDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_NEWFRAMERATE
VirtualFilter=dWC

[DLG:IDD_SETFLAGS]
Type=1
Class=CSetMainAVIHeaderFlagsDlg
ControlCount=10
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_SAHF_FLAGS,button,1342177287
Control4=IDC_HASINDEX,button,1342242819
Control5=IDC_MUSTUSEINDEX,button,1342242819
Control6=IDC_ISINTERLEAVED,button,1342242819
Control7=IDC_TRUSTCKTYPE,button,1342242819
Control8=IDC_WASCAPTUREFILE,button,1342242819
Control9=IDC_COPYRIGHTED,button,1342242819
Control10=IDC_SETFALGS_RESET,button,1342242816

[CLS:CSetMainAVIHeaderFlagsDlg]
Type=0
HeaderFile=SetMainAVIHeaderFlagsDlg.h
ImplementationFile=SetMainAVIHeaderFlagsDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=CSetMainAVIHeaderFlagsDlg
VirtualFilter=dWC

[CLS:CSetOpenFileOptionsDlg]
Type=0
HeaderFile=SetOpenFileOptionsDlg.h
ImplementationFile=SetOpenFileOptionsDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=CSetOpenFileOptionsDlg
VirtualFilter=dWC

[DLG:IDD_VIDEOINFO (Englisch (USA))]
Type=1
Class=CVideoInformationDlg
ControlCount=3
Control1=IDOK,button,1342242817
Control2=IDE_VIDEOINFORMATION,listbox,1352728833
Control3=IDC_APPLYREPAIRS,button,1342242816

[DLG:IDD_SETFRAMERATE (Englisch (USA))]
Type=1
Class=CSetFramerateDlg
ControlCount=7
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_NEWFRAMERATE,edit,1350631552
Control4=IDC_STATIC,button,1342177287
Control5=IDR_FR_FPS,button,1342177289
Control6=IDR_FR_MSPF,button,1342177289
Control7=IDR_FR_NSPF,button,1342177289

[DLG:IDD_SETFLAGS (Englisch (USA))]
Type=1
Class=CSetMainAVIHeaderFlagsDlg
ControlCount=10
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,button,1342177287
Control4=IDC_HASINDEX,button,1342242819
Control5=IDC_MUSTUSEINDEX,button,1342242819
Control6=IDC_ISINTERLEAVED,button,1342242819
Control7=IDC_TRUSTCKTYPE,button,1342242819
Control8=IDC_WASCAPTUREFILE,button,1342242819
Control9=IDC_COPYRIGHTED,button,1342242819
Control10=IDC_SETFALGS_RESTORE,button,1342242816

[DLG:IDD_OPENFILEOPTIONS (Englisch (USA))]
Type=1
Class=CSetOpenFileOptionsDlg
ControlCount=18
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,button,1342177287
Control4=IDC_OFO_AVI_IGNORECHUNKS,button,1342242819
Control5=IDC_OFO_AVI_IGNOREKBYTE,edit,1350631552
Control6=IDC_STATIC,static,1342308352
Control7=IDC_OFO_AVI_TRYTOREPAIRLARGECHUNKS,button,1342242819
Control8=IDC_STATIC,button,1342177287
Control9=IDC_OFO_M2F2CRCCHECK,button,1342242819
Control10=IDC_STATIC,button,1342177287
Control11=IDC_OFO_MP3_CHECKCBRALWAYS,button,1342177289
Control12=IDC_OFO_MP3_CHECKCBRASK,button,1342177289
Control13=IDC_OFO_MP3_CHECKCBRNEVER,button,1342177289
Control14=IDC_OFO_AVI_FORCEMP3VBR,button,1342242819
Control15=IDC_OFO_AVI_REPAIRDX50,button,1342242819
Control16=IDC_STATIC,button,1342177287
Control17=IDC_OFO_CONCAT_ALLOWCRAPAC3,button,1342242819
Control18=IDC_OFO_MP3_RESULTDLG,button,1342242819

[CLS:CSetStoreFileOptionsDlg]
Type=0
HeaderFile=SetStoreFileOptionsDlg.h
ImplementationFile=SetStoreFileOptionsDlg.cpp
BaseClass=CResizeableDialog
Filter=D
VirtualFilter=dWC
LastObject=IDC_MKV3_USE_A_AAC

[DLG:IDD_SAVEAVIOPTIONS (Englisch (USA))]
Type=1
Class=CSetStoreFileOptionsDlg
ControlCount=31
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_RECLISTS,button,1342242819
Control4=IDC_STATIC,static,1342308352
Control5=IDC_STATIC,button,1342308359
Control6=IDC_AUDIOINTERLEAVE,edit,1350639744
Control7=IDC_STATIC,static,1342308352
Control8=IDC_PRELOAD,edit,1350631552
Control9=IDC_MAXFILESIZE,edit,1350631552
Control10=IDC_FORMAT,edit,1350631552
Control11=IDC_STATIC,static,1342308352
Control12=IDC_MAXFRAMES,edit,1350631552
Control13=IDC_OPENDML,button,1342242819
Control14=IDC_MAXSIZE_EXTENDED,button,1342242816
Control15=IDC_USESPLITPOINTLIST,button,1342242819
Control16=IDC_USEMAXSIZE,button,1342242819
Control17=IDC_AI_KB,button,1342177289
Control18=IDC_AI_FRAMES,button,1342177289
Control19=IDC_STATIC,button,1342177287
Control20=IDC_STATIC,button,1342177287
Control21=IDC_MAXFILES,edit,1350631552
Control22=IDC_USEMAXFILES,button,1342242819
Control23=IDC_USENUMBERING,button,1342242819
Control24=IDC_MAKEIDX1,button,1342242819
Control25=IDC_ODML_SETTINGS,button,1342308359
Control26=IDC_STATIC,static,1342308352
Control27=IDC_STDI_RIFF,button,1342177289
Control28=IDC_STDI_FRAMES,button,1342177289
Control29=IDC_STDI_AUTO,button,1342177289
Control30=IDC_STDI_NBROFFRAMES,edit,1350631552
Control31=IDC_STATIC,static,1342308352

[CLS:CEnhancedListBox]
Type=0
HeaderFile=EnhancedListBox.h
ImplementationFile=EnhancedListBox.cpp
BaseClass=CListBox
Filter=W
VirtualFilter=bWC
LastObject=IDC_AVAILABLETEXTSTREAMS

[CLS:CVideoSourceListBox]
Type=0
HeaderFile=VideoSourceListBox.h
ImplementationFile=VideoSourceListBox.cpp
BaseClass=CEnhancedListBox
Filter=W
VirtualFilter=bWC
LastObject=CVideoSourceListBox

[CLS:CSubtitlesListBox]
Type=0
HeaderFile=SubtitlesListBox.h
ImplementationFile=SubtitlesListBox.cpp
BaseClass=CEnhancedListBox
Filter=W
VirtualFilter=bWC
LastObject=CSubtitlesListBox

[MNU:IDR_LANGUAGES]
Type=1
Class=?
Command1=IDM_LANG1
Command2=IDM_LANG2
Command3=IDM_LANG3
Command4=IDM_LANG4
Command5=IDM_LANG5
Command6=IDM_LANG6
Command7=IDM_LANG7
Command8=IDM_LANG8
Command9=IDM_LANG9
Command10=IDM_LANG10
Command11=IDM_LANG11
Command12=IDM_LANG12
Command13=IDM_LANG13
Command14=IDM_LANG14
Command15=IDM_LANG15
Command16=IDM_LANG16
CommandCount=16

[DLG:IDD_RIFFCHUNKTREEDLG]
Type=1
Class=CRIFFChunkTreeDlg
ControlCount=4
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_TREE1,SysTreeView32,1350631431
Control4=IDC_SAVE,button,1342242816

[CLS:CRIFFChunkTreeDlg]
Type=0
HeaderFile=RIFFChunkTreeDlg.h
ImplementationFile=RIFFChunkTreeDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=CRIFFChunkTreeDlg
VirtualFilter=dWC

[MNU:IDR_SUBTITLEMENU]
Type=1
Class=?
Command1=IDM_EXTRACTSRT
Command2=IDM_EXTRACTSSA
CommandCount=2

[CLS:CProtocolListCtrl]
Type=0
HeaderFile=ProtocolListCtrl.h
ImplementationFile=ProtocolListCtrl.cpp
BaseClass=CListCtrl
Filter=W
VirtualFilter=FWC
LastObject=CProtocolListCtrl

[CLS:CProgressList]
Type=0
HeaderFile=ProgressList.h
ImplementationFile=ProgressList.cpp
BaseClass=CListCtrl
Filter=W
VirtualFilter=FWC
LastObject=CProgressList

[DLG:IDD_CHAPTERDIALOG]
Type=1
Class=CChapterDlg
ControlCount=14
Control1=IDOK,button,1342177280
Control2=IDCANCEL,button,1073741824
Control3=IDC_CHAPTERTREE,SysTreeView32,1350636079
Control4=IDC_MAKESUBCHAPTER,button,1342177280
Control5=IDC_SAVEAS,button,1342177280
Control6=IDC_BUTTON3,button,1073741825
Control7=IDC_CHAPTER_DISPLAY,SysListView32,1350598669
Control8=IDC_CHAPTERDISPLAY_LNG,combobox,1344340226
Control9=IDC_CHAPTERS_USAGE_LABEL,static,1342308352
Control10=IDC_CHAPTERSEGMENTUID,edit,1350631552
Control11=IDC_CHAPTERSEGMENTUID_LABEL,static,1342308352
Control12=IDC_CHAPTERUID_LABEL,static,1342308352
Control13=IDC_CHAPTERUID,edit,1484851328
Control14=IDC_CHAPTER_TITLE,edit,1350631552

[CLS:CChapterDlg]
Type=0
HeaderFile=ChapterDlg.h
ImplementationFile=ChapterDlg.cpp
BaseClass=CResizeableDialog
Filter=D
LastObject=IDC_CHAPTER_DISPLAY
VirtualFilter=dWC

[CLS:CChapterDlgTree]
Type=0
HeaderFile=ChapterDlgTree.h
ImplementationFile=ChapterDlgTree.cpp
BaseClass=CUnicodeTreeCtrl
Filter=W
VirtualFilter=GWC
LastObject=CChapterDlgTree

[CLS:CAudioSourceTree]
Type=0
HeaderFile=AudioSourceTree.h
ImplementationFile=AudioSourceTree.cpp
BaseClass=CUnicodeTreeCtrl
Filter=W
VirtualFilter=GWC
LastObject=CAudioSourceTree

[DLG:IDD_SETOUTPUTOPTIONS]
Type=1
Class=CSetStoreFileOptionsDlg
ControlCount=151
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_RECLISTS,button,1342242819
Control4=IDC_SAUDIOINTERLEAVE,static,1342308352
Control5=IDC_SFO_OPTIONS,button,1073872903
Control6=IDC_AUDIOINTERLEAVE,edit,1350639744
Control7=IDC_SPRELOAD,static,1342308352
Control8=IDC_PRELOAD,edit,1350631552
Control9=IDC_MAXFILESIZE,edit,1350631552
Control10=IDC_FORMAT,edit,1350631552
Control11=IDC_SFO_OSP_FRAMES,static,1342308352
Control12=IDC_MAXFRAMES,edit,1350631552
Control13=IDC_OPENDML,button,1342242819
Control14=IDC_MAXSIZE_EXTENDED,button,1342242816
Control15=IDC_USESPLITPOINTLIST,button,1342242819
Control16=IDC_USEMAXSIZE,button,1342242819
Control17=IDC_MAKEIDX1,button,1342242819
Control18=IDC_AI_KB,button,1342177289
Control19=IDC_AI_FRAMES,button,1342177289
Control20=IDC_SFO_O_AVISTRUCTURE,button,1342177287
Control21=IDC_SFO_O_SPLIT,button,1342177287
Control22=IDC_MAXFILES,edit,1350631552
Control23=IDC_USEMAXFILES,button,1342242819
Control24=IDC_USENUMBERING,button,1342242819
Control25=IDC_SFO_ODML_SETTINGS,button,1342308359
Control26=IDC_SFO_STDIDXPERSTREAM,static,1342308352
Control27=IDC_STDI_RIFF,button,1342177289
Control28=IDC_STDI_FRAMES,button,1342177289
Control29=IDC_STDI_AUTO,button,1342177289
Control30=IDC_STDI_NBROFFRAMES,edit,1350631552
Control31=IDC_SFO_FRAMES,static,1342308352
Control32=IDC_MP3CBRFRAMEMODE,button,1342242819
Control33=IDC_SFO_O_MKVPAGE1,button,1342177287
Control34=IDC_SFO_O_GENERAL,button,1342177287
Control35=IDC_STDOUTPUTFORMATS,combobox,1344340227
Control36=IDC_1STTIMESTAMP_LABEL,static,1342308352
Control37=IDC_1STTIMESTAMP,edit,1350631552
Control38=IDC_AC3FRAMECOUNT_LABEL,static,1342308352
Control39=IDC_AC3FRAMECOUNT,edit,1350633601
Control40=IDC_AC3FRAMECOUNT_SPIN,msctls_updown32,1342177312
Control41=IDC_DONTWRITEBLOCKSIZE,button,1342242819
Control42=IDC_STDOUTPUTFORMAT_LABEL,static,1342308352
Control43=IDC_CLUSTERSIZE_LABEL,static,1342308352
Control44=IDC_CLUSTERSIZE,edit,1350633601
Control45=IDC_CLUSTERSIZE_SPIN,msctls_updown32,1342177312
Control46=IDC_MKV_LACESIZE,edit,1350633601
Control47=IDC_MKV_LACESIZE_SPIN,msctls_updown32,1342177312
Control48=IDC_CLUSTERTIME_LABEL,static,1342308352
Control49=IDC_CLUSTERTIME,edit,1350633601
Control50=IDC_CLUSTERTIME_SPIN,msctls_updown32,1342177312
Control51=IDC_MKV_PREVSIZE,button,1342242819
Control52=IDC_MKV_POSITION,button,1342242819
Control53=IDC_1STCL_30sec,button,1342242819
Control54=IDC_RADIO_OUTPUT_AVI,button,1342320649
Control55=IDC_RADIO_OUTPUT_GENERAL,button,1342181385
Control56=IDC_RADIO_OUTPUT_MKV,button,1342181385
Control57=IDC_RADIO_INPUT_AVIMP3,button,1342181385
Control58=IDC_RADIO_INPUT_MKV,button,1342181385
Control59=IDC_RADIO_INPUT_GENERAL,button,1342181385
Control60=IDC_MKV_AC3FRAMESPERBLOCK_LABEL,static,1073872896
Control61=IDC_MKV_AC3FRAMESPERBLOCK,edit,1082198144
Control62=IDC_MKV_AC3FRAMESPERBLOCK_SPIN,msctls_updown32,1073741856
Control63=IDC_LACESTYLE,combobox,1344339970
Control64=IDC_MKV_LACE,static,1342308352
Control65=IDC_IAVI_Label,button,1342177287
Control66=IDC_STATIC,static,1342308352
Control67=IDC_STATIC,static,1342308352
Control68=IDC_IMP3_LABEL,button,1342177287
Control69=IDC_IMP3_CHECKALWAYS,button,1342177289
Control70=IDC_IMP3_ASK,button,1342177289
Control71=IDC_IMP3_CHECKNEVER,button,1342177289
Control72=IDC_IMP3_DISPRESULT,button,1342242819
Control73=IDC_IAVI_IGNORECHUNKS_LABEL,button,1342251011
Control74=IDC_IAVI_IGNOREKBYTE,edit,1350631552
Control75=IDC_IAVI_TRYTOREPAIRLARGECHUNKS,button,1342251011
Control76=IDC_IAVI_FORCEMP3VBR,button,1342251011
Control77=IDC_IAVI_REPAIRDX50,button,1342251011
Control78=IDC_IM2F2_LABEL,button,1342177287
Control79=IDC_IM2F2_CRCCHECK,button,1342251011
Control80=IDC_IMKV_Label,button,1342177287
Control81=IDC_IMKV_CHAPTERS_LABEL,button,1342177287
Control82=IDC_I_CH_FROMFILENAMES,button,1342242819
Control83=IDC_IMKV_CH_IMPORT,button,1342242819
Control84=IDC_OVERLAPPED,button,1342242819
Control85=IDC_MKV_DISPWH,button,1342242819
Control86=IDC_LACEEXCEPTIONFORMATSPIN,msctls_updown32,1342177312
Control87=IDC_LACEEXCEPTIONFORMAT,edit,1350631552
Control88=IDC_USELACINGEXCEPTION,button,1342242819
Control89=IDC_LACEVIDEO,button,1342242819
Control90=IDC_LACEVIDEO_COUNT,edit,1350633601
Control91=IDC_LACEVIDEO_SPIN,msctls_updown32,1342177312
Control92=IDC_FORCEMKV1,button,1342242819
Control93=IDC_WRITECUES,button,1342242819
Control94=IDC_WRITECUES_VIDEO,button,1342242819
Control95=IDC_WRITECUES_AUDIO,button,1342242819
Control96=IDC_WRITECUES_ONLYAUDIOONLY,button,1342242819
Control97=IDC_MKV_CUES,button,1342177287
Control98=IDC_MKV_LACING,button,1342177287
Control99=IDC_MKV_CLUSTER,button,1342177287
Control100=IDC_SFO_O_MKVPAGE2,button,1342177287
Control101=IDC_TCS_MKV_LABEL,static,1342308352
Control102=IDC_TCS_MKV,edit,1350631554
Control103=IDC_TCS_MKA_LABEL,static,1342308352
Control104=IDC_TCS_MKA,edit,1350631554
Control105=IDC_MKV_PAGE1,button,1342312457
Control106=IDC_MKV_PAGE2,button,1342181385
Control107=IDC_OUTPUT_MKV3_OTHERS,button,1342177287
Control108=IDC_2ndCopieOfTracks,button,1342242819
Control109=IDC_TIMECODESCALE,button,1342177287
Control110=IDC_INDEXINSEEKHEAD,button,1342242819
Control111=IDC_LOGFILE,button,1342242819
Control112=IDC_RIFFAVISIZE,edit,1350631553
Control113=IDC_RIFFAVISIZE_LABEL,static,1342308352
Control114=IDC_RIFFAVISIZE_UNIT,static,1342308352
Control115=IDC_SFO_I_GENERAL,button,1342177287
Control116=IDC_AVOIDSEEKOPS,button,1342242819
Control117=IDC_SFO_ALLOWUNBUFFEREDREAD,button,1342242819
Control118=IDC_SFO_ALLOWUNBUFFEREDWRITE,button,1342242819
Control119=IDC_SFO_O_AVISTRUCTURE2,button,1342177287
Control120=IDC_AVI_PAGE1,button,1342181385
Control121=IDC_AVI_PAGE2,button,1342181385
Control122=IDC_MP3VBRFRAMECOUNT_LABEL,static,1342308352
Control123=IDC_MP3VBRFRAMECOUNT,edit,1350631553
Control124=IDC_FLOATWIDTH_LABEL,static,1342308352
Control125=IDC_FLOATWIDTH,edit,1350633601
Control126=IDC_FLOATWIDTH_SPIN,msctls_updown32,1342177312
Control127=IDC_DTSFRAMECOUNT,edit,1350631553
Control128=IDC_DTSFRAMECOUNT_LABEL,static,1342308352
Control129=IDC_RANDOMIZE_ELEMENT_ORDER,button,1342242819
Control130=IDC_HAALIMODE,button,1342242819
Control131=IDC_MOVEHDRL,button,1342242819
Control132=IDC_NONCLUSTERTOFIRSTSEEKHEAD,button,1342242819
Control133=IDC_MKV_HEADERSIZE_LABEL,static,1342308352
Control134=IDC_MKV_HEADERSIZE,edit,1350631553
Control135=IDC_WRITECUES_SUBS,button,1342242819
Control136=IDC_SFO_O_MKVPAGE3,button,1342177287
Control137=IDC_MKV_PAGE3,button,1342181385
Control138=IDC_CUE_MINIMUM_INTERVAL_LABEL,static,1342308352
Control139=IDC_CUES_AUTOSIZE,button,1342242819
Control140=IDC_CUE_MINIMUM_INTERVAL,edit,1350631553
Control141=IDC_SIZE_PER_STREAM_AND_HOUR_LABEL,static,1342308352
Control142=IDC_SIZE_PER_STREAM_AND_HOUR,edit,1350631553
Control143=IDC_CUE_INTERVAL_SETTINGS_LABEL,button,1342177287
Control144=IDC_CUE_TARGET_SIZE_RATIO_LABEL,static,1342308352
Control145=IDC_CUE_TARGET_SIZE_RATIO,edit,1350631553
Control146=IDC_MKV_HARD_LINKING,button,1342242819
Control147=IDC_WRITECUES_BLOCKNUMBER,button,1342242819
Control148=IDC_INPUT_OVERLAPPED,button,1342242819
Control149=IDC_HEADER_STRIPPING,button,1342242819
Control150=IDC_FORCEMKV2,button,1342242819
Control151=IDC_MKV3_USE_A_AAC,button,1342242819

[CLS:CUserDrawEdit]
Type=0
HeaderFile=UserDrawEdit.h
ImplementationFile=UserDrawEdit.cpp
BaseClass=CEdit
Filter=W
VirtualFilter=WC
LastObject=CUserDrawEdit

[CLS:CClusterTimeEdit]
Type=0
HeaderFile=ClusterTimeEdit.h
ImplementationFile=ClusterTimeEdit.cpp
BaseClass=CEdit
Filter=W

[CLS:CAC3FrameCountEdit]
Type=0
HeaderFile=AC3FrameCountEdit.h
ImplementationFile=AC3FrameCountEdit.cpp
BaseClass=CEdit
Filter=W
LastObject=CAC3FrameCountEdit

[CLS:CMKVAC3FrameCountEdit]
Type=0
HeaderFile=MKVAC3FrameCountEdit.h
ImplementationFile=MKVAC3FrameCountEdit.cpp
BaseClass=CEdit
Filter=W

[DLG:IDD_EBMLTREE_DLG]
Type=1
Class=CEBMLTreeDlg
ControlCount=7
Control1=IDOK,button,1342242817
Control2=IDC_TREE1,SysTreeView32,1350631447
Control3=IDC_ABSOLUTE,button,1342177289
Control4=IDC_RELATIVE,button,1342177289
Control5=IDC_FULLEXPAND,button,1073807360
Control6=IDC_FONT_LARGER,button,1342242816
Control7=IDC_FONT_SMALLER,button,1342242816

[CLS:CEBMLTreeDlg]
Type=0
HeaderFile=EBMLTreeDlg.h
ImplementationFile=EBMLTreeDlg.cpp
BaseClass=CResizeableDialog
Filter=D
VirtualFilter=dWC
LastObject=CEBMLTreeDlg

[CLS:CEBMLTree]
Type=0
HeaderFile=EBMLTree.h
ImplementationFile=EBMLTree.cpp
BaseClass=CTreeCtrl
Filter=W
VirtualFilter=GWC
LastObject=CEBMLTree

[CLS:CUnicodeTreeCtrl]
Type=0
HeaderFile=UnicodeTreeCtrl.h
ImplementationFile=UnicodeTreeCtrl.cpp
BaseClass=CTreeCtrl
Filter=W
VirtualFilter=GWC
LastObject=CUnicodeTreeCtrl

[CLS:CChapterDlgList]
Type=0
HeaderFile=ChapterDlgList.h
ImplementationFile=ChapterDlgList.cpp
BaseClass=CListCtrl
Filter=W
LastObject=CChapterDlgList

[CLS:CChapterSegmentUIDEdit]
Type=0
HeaderFile=ChapterSegmentUIDEdit.h
ImplementationFile=ChapterSegmentUIDEdit.cpp
BaseClass=CUserDrawEdit
Filter=W
LastObject=CChapterSegmentUIDEdit
VirtualFilter=WC

[CLS:CVerifyEdit]
Type=0
HeaderFile=VerifyEdit.h
ImplementationFile=VerifyEdit.cpp
BaseClass=CEdit
Filter=W

[CLS:CResolutionEdit]
Type=0
HeaderFile=ResolutionEdit.h
ImplementationFile=ResolutionEdit.cpp
BaseClass=CEdit
Filter=W
LastObject=CResolutionEdit

[CLS:CMKVHeaderSizeEdit]
Type=0
HeaderFile=MKVHeaderSizeEdit.h
ImplementationFile=MKVHeaderSizeEdit.cpp
BaseClass=CEdit
Filter=W

[CLS:CResizeableDialog]
Type=0
HeaderFile=ResizeableDialog.h
ImplementationFile=ResizeableDialog.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CResizeableDialog

