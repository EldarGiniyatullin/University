primeLess :: Integer -> [Integer]
primeLess 1 = [2]
primeLess 2 = [2]
primeLess a = [n | n <- [2..a], ((filter ((==1).(gcd n)) ((n - 1):(primeLess (n-1)))) == [])]