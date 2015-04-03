import Data.Maybe

findPos :: (Eq a) => a -> [a] -> Maybe Int
findPos x xs = if (a /= 0) then Just a else Nothing where
				a = (length xs) - (length $ dropWhile (/= x) xs)