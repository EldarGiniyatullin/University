mapSpec :: Num a => [a] -> [a]
mapSpec [] = []
mapSpec (x:xs) = (z + 1):(z + 7):(z + 9):(mapSpec xs) where
	z = x * 10

list179 = oneSevenNine where
	oneSevenNine0 = mapSpec oneSevenNine
	oneSevenNine = 1:7:9:oneSevenNine0