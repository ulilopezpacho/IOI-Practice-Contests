uses scales, graderlib, CTypes;

var
    T: longint;
    i: longint;

begin
    T := _getNumberOfTests();
    init(T);
    
    for i := 1 to T do begin
        _initNewTest; 
        orderCoins;
    end;
end.
