reverse1 :: [a] -> [a] -> [a]
reverse1 [] xs = xs
reverse1 (x:xs) acc = reverse1 (xs) (x:acc)

reverseList :: [a] -> [a]
reverseList xs = reverse1 xs []

isPalindrom :: Eq a => [a] -> Bool
isPalindrom [] = True
isPalindrom [x] = True
isPalindrom xs = if xs == reverseList xs then True else False
