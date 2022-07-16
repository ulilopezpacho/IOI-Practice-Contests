program grader;

uses elephants, graderhelplib;

type
updateFunction = function (id : longint; nv : longint) : longint; cdecl;
initFunction = procedure (n : longint; l : longint; var xs : array of longint); cdecl;

{$L graderlib.o}
{$IFDEF MSWINDOWS}
{$linklib msvcrt}
{$ELSE}
{$linklib c}
{$ENDIF}

procedure _main(init : initFunction; update : updateFunction); cdecl; external;

begin
    _main(@init, @update);
end.
