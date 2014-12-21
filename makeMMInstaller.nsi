; NSIS Script

!include "MUI2.nsh"
;セミコロンからはじまる行はコメント。
!define NAME "MogiMeijin"
!define VERSION "1.0"
!define PACKAGE "${NAME}${VERSION}"
!define APPDIR ""
;"!define" は定数定義の命令。プログラムの名前やバージョンを設定している。
Name "${PACKAGE}"
OutFile "${PACKAGE}Setup.exe"
;プログラムの名前とインストーラのファイル名の設定。
InstallDir "$PROGRAMFILES\${NAME}\${PACKAGE}"
;InstallDirRegKey HKLM "SOFTWARE\${PACKAGE}" ""
;インストールディレクトリとレジストリキーの設定。
RequestExecutionLevel user
;実行権限の指定。"admin" だと管理者しか実行できない。"user" ならば制限ユーザーでも実行できる。
!define MUI_ICON "${NSISDIR}\Contrib\Graphics\Icons\MeiIcon4.ico"
 
!define MUI_HEADERIMAGE
!define MUI_HEADERIMAGE_RIGHT
!define MUI_HEADERIMAGE_BITMAP "${NSISDIR}\Contrib\Graphics\Header\catch.bmp"
 
!define MUI_WELCOMEFINISHPAGE_BITMAP "${NSISDIR}\Contrib\Graphics\Wizard\arrow.bmp"
;インストーラの見た目の設定。好みの問題。
!define MUI_ABORTWARNING
;これが定義されていると、インストールを中断するときに警告を出す。
!insertmacro MUI_PAGE_WELCOME
!insertmacro MUI_PAGE_DIRECTORY
!insertmacro MUI_PAGE_INSTFILES
    !define MUI_FINISHPAGE_RUN_TEXT "せっかくやし、ついでに${PACKAGE}を起動する"
    !define MUI_FINISHPAGE_RUN "$INSTDIR\${NAME}.exe"
!insertmacro MUI_PAGE_FINISH
;インストールのページ設定。順番に、ようこそページ、インストール先フォルダ指定ページ、インストール中ページ、完了ページ。
!insertmacro MUI_LANGUAGE "English"
!insertmacro MUI_LANGUAGE "Japanese"
;言語設定。デフォルトは英語、"Japanese" を加えておけば OS の言語設定が日本語の場合にインストーラのメッセージが日本語になる。

  BrandingText "${PACKAGE} Installer by NSIS"
  SetFont "Meiryo UI" 8
  ComponentText "インストールしたいフォルダを選んでね！"
  InstallColors FF8000 FFFFFF
  InstProgressFlags smooth colored
  SubCaption 2 "インストールしたいフォルダを選んでね！"
  CompletedText "これで${NAME}が使えます！！"
  ShowInstDetails show


Section

  SectionIn RO

  SetOutPath $INSTDIR
  File /r "Release\AutoIt"
  File /r "Release\css"
  File /r "Release\icon"
  File /r "Release\ja"
  File /r "Release\sample"
  File "Release\*.dll"
  File "Release\*.xml"
  File "Release\*.exe"
  File "Release\*.pdb"
  File "Release\*.metagen"
  File "Release\*.pdf"
  File "Release\*.txt"
  File "Release\*.png"
  
  SetShellVarContext all
  ; CreateDirectory "$SMPROGRAMS\${PACKAGE}"
  ; CreateShortCut "$SMPROGRAMS\${PACKAGE}\MogiMeijin.lnk" "$INSTDIR\MogiMeijin.exe"
  ; CreateShortCut "$DESKTOP\MogiMeijin.lnk" "$INSTDIR\MogiMeijin.exe"
  ;CreateShortCut "$SMPROGRAMS\${PACKAGE}\TeXMeijinManual.lnk" "$INSTDIR\TeXMeijinManual1.3.pdf"
  ;CreateShortCut "$SMPROGRAMS\${PACKAGE}\TeXMeijinManual(追記).lnk" "$INSTDIR\TeXMeijinManual追記！！.pdf"
  
SectionEnd
;インストール処理の記述。以下でそれぞれ説明する。
;  SetOutPath $INSTDIR
;  File "${APPDIR}\README.txt"
;  File "${APPDIR}\doc\manual.pdf"
;  File /r "${APPDIR}\sample"
;"File" は直前の "SetOutPath" で設定されたパスにファイルをコピーする。"/r" オプションをつけるとフォルダごとコピー;する。ここではインストール先フォルダ $INSTDIR (InstallDir で指定したディレクトリ) にパッケージの README.txt, doc/;manual.pdf, sample フォルダをコピーしている。
;  SetShellVarContext all
;  CreateDirectory "$SMPROGRAMS\${PACKAGE}"
;  CreateShortCut "$SMPROGRAMS\${PACKAGE}\manual.lnk" "$INSTDIR\manual.pdf"
;  CreateShortCut "$SMPROGRAMS\${PACKAGE}\sample.lnk" "$INSTDIR\sample"
;  CreateShortCut "$SMPROGRAMS\${PACKAGE}\Uninstall.lnk" "$INSTDIR\uninstall.exe"
;スタートメニューの設定。"SetShellVarContext all" は "All Users" のスタートメニューを使うことを指示している。それ以降はフォルダを作りその中にショートカットを作っている。