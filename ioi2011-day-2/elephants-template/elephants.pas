unit elephants;

interface

function update(id : longint; nv : longint) : longint; cdecl;
procedure init(n : longint; l : longint; var xs : array of longint); cdecl;

implementation

function update(id : longint; nv : longint) : longint; cdecl;
begin
   update := id xor nv;
end;

procedure init(n : longint; l : longint; var xs : array of longint); cdecl;
begin
end;

begin
end.
