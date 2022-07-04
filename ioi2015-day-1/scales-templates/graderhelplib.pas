unit graderhelplib;

interface

procedure answer(var C: array of LongInt); external;
function getMedian(A, B, C: LongInt): LongInt; external;
function getHeaviest(A, B, C: LongInt): LongInt; external;
function getLightest(A, B, C: LongInt): LongInt; external;
function getNextLightest(A, B, C, D: LongInt): LongInt; external;

implementation

end.
