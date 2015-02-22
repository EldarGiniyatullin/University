sumOfDigits :: Integer -> Integer
sumOfDigits 0 = 0
sumOfDigits x = a + (sumOfDigits b) where
	a = x `mod` 10
	b = x `div` 10