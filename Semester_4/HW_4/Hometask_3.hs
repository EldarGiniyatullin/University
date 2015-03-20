import Test.QuickCheck

func1 :: [Int] -> Int
func1 = length . (filter (== 0)) . (map (`mod` 2))

func2 :: [Int] -> Int
func2 = foldr ((+) . (`mod` 2) . (+ 1) .abs) 0

func3 :: [Int] -> Int
func3 = length . filter ((== 0) .(`mod` 2))

main = quickCheck (\xs -> ((func1 xs == func2 xs) && (func3 xs == func2 xs))) 