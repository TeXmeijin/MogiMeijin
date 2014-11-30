; NSIS Script

!include "MUI2.nsh"
;�Z�~�R��������͂��܂�s�̓R�����g�B
!define NAME "MogiMeijin"
!define VERSION "1.0"
!define PACKAGE "${NAME}${VERSION}"
!define APPDIR ""
;"!define" �͒萔��`�̖��߁B�v���O�����̖��O��o�[�W������ݒ肵�Ă���B
Name "${PACKAGE}"
OutFile "${PACKAGE}Setup.exe"
;�v���O�����̖��O�ƃC���X�g�[���̃t�@�C�����̐ݒ�B
InstallDir "$PROGRAMFILES\${NAME}\${PACKAGE}"
;InstallDirRegKey HKLM "SOFTWARE\${PACKAGE}" ""
;�C���X�g�[���f�B���N�g���ƃ��W�X�g���L�[�̐ݒ�B
RequestExecutionLevel user
;���s�����̎w��B"admin" ���ƊǗ��҂������s�ł��Ȃ��B"user" �Ȃ�ΐ������[�U�[�ł����s�ł���B
!define MUI_ICON "${NSISDIR}\Contrib\Graphics\Icons\MeiIcon4.ico"
 
!define MUI_HEADERIMAGE
!define MUI_HEADERIMAGE_RIGHT
!define MUI_HEADERIMAGE_BITMAP "${NSISDIR}\Contrib\Graphics\Header\catch.bmp"
 
!define MUI_WELCOMEFINISHPAGE_BITMAP "${NSISDIR}\Contrib\Graphics\Wizard\arrow.bmp"
;�C���X�g�[���̌����ڂ̐ݒ�B�D�݂̖��B
!define MUI_ABORTWARNING
;���ꂪ��`����Ă���ƁA�C���X�g�[���𒆒f����Ƃ��Ɍx�����o���B
!insertmacro MUI_PAGE_WELCOME
!insertmacro MUI_PAGE_DIRECTORY
!insertmacro MUI_PAGE_INSTFILES
    !define MUI_FINISHPAGE_RUN_TEXT "���������₵�A���ł�${PACKAGE}���N������"
    !define MUI_FINISHPAGE_RUN "$INSTDIR\${NAME}.exe"
!insertmacro MUI_PAGE_FINISH
;�C���X�g�[���̃y�[�W�ݒ�B���ԂɁA�悤�����y�[�W�A�C���X�g�[����t�H���_�w��y�[�W�A�C���X�g�[�����y�[�W�A�����y�[�W�B
!insertmacro MUI_LANGUAGE "English"
!insertmacro MUI_LANGUAGE "Japanese"
;����ݒ�B�f�t�H���g�͉p��A"Japanese" �������Ă����� OS �̌���ݒ肪���{��̏ꍇ�ɃC���X�g�[���̃��b�Z�[�W�����{��ɂȂ�B

  BrandingText "${PACKAGE} Installer by NSIS"
  SetFont "Meiryo UI" 8
  ComponentText "�C���X�g�[���������t�H���_��I��łˁI"
  InstallColors FF8000 FFFFFF
  InstProgressFlags smooth colored
  SubCaption 2 "�C���X�g�[���������t�H���_��I��łˁI"
  CompletedText "�����${NAME}���g���܂��I�I"
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
  ;CreateShortCut "$SMPROGRAMS\${PACKAGE}\TeXMeijinManual(�ǋL).lnk" "$INSTDIR\TeXMeijinManual�ǋL�I�I.pdf"
  
SectionEnd
;�C���X�g�[�������̋L�q�B�ȉ��ł��ꂼ���������B
;  SetOutPath $INSTDIR
;  File "${APPDIR}\README.txt"
;  File "${APPDIR}\doc\manual.pdf"
;  File /r "${APPDIR}\sample"
;"File" �͒��O�� "SetOutPath" �Őݒ肳�ꂽ�p�X�Ƀt�@�C�����R�s�[����B"/r" �I�v�V����������ƃt�H���_���ƃR�s�[;����B�����ł̓C���X�g�[����t�H���_ $INSTDIR (InstallDir �Ŏw�肵���f�B���N�g��) �Ƀp�b�P�[�W�� README.txt, doc/;manual.pdf, sample �t�H���_���R�s�[���Ă���B
;  SetShellVarContext all
;  CreateDirectory "$SMPROGRAMS\${PACKAGE}"
;  CreateShortCut "$SMPROGRAMS\${PACKAGE}\manual.lnk" "$INSTDIR\manual.pdf"
;  CreateShortCut "$SMPROGRAMS\${PACKAGE}\sample.lnk" "$INSTDIR\sample"
;  CreateShortCut "$SMPROGRAMS\${PACKAGE}\Uninstall.lnk" "$INSTDIR\uninstall.exe"
;�X�^�[�g���j���[�̐ݒ�B"SetShellVarContext all" �� "All Users" �̃X�^�[�g���j���[���g�����Ƃ��w�����Ă���B����ȍ~�̓t�H���_����肻�̒��ɃV���[�g�J�b�g������Ă���B