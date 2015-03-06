counter1 :: [Int] -> Int -> Int -> Int -> Int
counter1 [] acc pos curr = pos
counter1 [a] acc pos curr = pos
counter1 [a, b] acc pos curr = pos
counter1 (x:y:z:xs) acc pos curr = if ((x + z) > acc) then (counter1 (y:z:xs) (x + z) (pos + curr) 1) else (counter1 (y:z:xs) acc pos (curr + 1))

counter :: [Int] -> Int
counter [] = 0
counter [a] = 0
counter [a, b] = 0
counter xs = counter1 xs (minBound :: Int) 1 1