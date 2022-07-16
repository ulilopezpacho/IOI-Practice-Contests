unit parrots;

interface 
  uses graderhelplib;

  procedure encode(N:longint; M: array of Longint); cdecl;
  procedure decode(N, L:longint; X: array of Longint); cdecl;

implementation


procedure encode(N:longint; M: array of Longint); cdecl;
begin
    send(1);
    send(2);
    send(3);
end;

procedure decode(N, L:longint; X: array of Longint); cdecl;
begin
   output(42);
end;

begin
end.