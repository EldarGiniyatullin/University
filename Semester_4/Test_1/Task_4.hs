sumCosH :: (Floating a) => [a] -> a -> a -> a
sumCosH [] accCos accSum = accSum / accCos
sumCosH (x:xs) accCos accSum = sumCosH xs (accCos * (cos x)) (accSum + x)

sumCos :: (Floating a) => [a] -> a
sumCos xs = sumCosH xs 1 0