program grader;

uses parrots;

type
  encodeFunction = procedure (N : longint; X: array of Longint); cdecl;
  decodeFunction = procedure (N, L:longint; X: array of Longint); cdecl;

{$L graderlib.o}
{$IFDEF MSWINDOWS}
{$linklib msvcrt}
{$ELSE}
{$linklib c}
{$ENDIF}

procedure _main(encode: encodeFunction; decode: decodeFunction); cdecl; external;

begin
    _main(@encode, @decode);
end.