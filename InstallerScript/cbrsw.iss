; -- cbrsw.iss --
; instalator for cbrsw program

[Setup]
AppName=Bracket Switcher
AppVersion=1.1
PrivilegesRequired=admin
AlwaysRestart=yes
WizardStyle=modern
DefaultDirName={autopf}\cbrsw
DefaultGroupName=BracketSwitcher
UninstallDisplayIcon={app}\RemoveCbrsw.exe
Compression=lzma2
SolidCompression=yes
ArchitecturesAllowed=x64
ArchitecturesInstallIn64BitMode=x64

[Code]
function NeedsAddPath(Param: string): boolean;
var
  OrigPath: string;
begin
  if not RegQueryStringValue(HKEY_LOCAL_MACHINE,
    'SYSTEM\CurrentControlSet\Control\Session Manager\Environment',
    'Path', OrigPath)
  then begin
    Result := True;
    exit;
  end;
  { look for the path with leading and trailing semicolon }
  { Pos() returns 0 if not found }
  Result := Pos(';' + Param + ';', ';' + OrigPath + ';') = 0;
end;

[Registry]
Root: HKLM; Subkey: "SYSTEM\CurrentControlSet\Control\Session Manager\Environment"; \
  ValueType: expandsz; ValueName: "Path"; ValueData: "{olddata};C:\Program Files\cbrsw"; \
  Check: NeedsAddPath('C:\Program Files\cbrsw')

[Files]
Source: "cbrsw.exe"; DestDir: "C:\Program Files\cbrsw"; DestName: "cbrsw.exe"

