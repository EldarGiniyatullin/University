reverse1 :: [a] -> [a] -> [a]
reverse1 [] xs = xs
reverse1 (x:xs) acc = reverse1 (xs) (x:acc)

reverseList :: [a] -> [a]
reverseList xs = reverse1 xs []