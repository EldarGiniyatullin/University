counter1 :: (Ord a, Num a) => [a] -> a -> Integer -> Integer -> Integer
counter1 [] acc pos curr = pos
counter1 [a] acc pos curr = pos
counter1 [a, b] acc pos curr = pos
counter1 (x:y:z:xs) acc pos curr = if ((x + z) > acc) then (counter1 (y:z:xs) (x + z) (pos + curr) 1) else (counter1 (y:z:xs) acc pos (curr + 1))

counter :: (Ord a, Num a) => [a] -> Integer
counter xs = counter1 xs 0 1 1