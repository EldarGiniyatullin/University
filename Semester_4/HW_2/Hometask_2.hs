digitsOf2 :: Integer -> [Integer]
digitsOf2 n = [2^x | x <- [1..n] ]