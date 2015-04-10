import Control.Monad
import Control.Exception

addSorted :: (Ord a) => [a] -> a -> [a]
addSorted [] s = [s]
addSorted (x:xs) s 
	| (s > x) = x:(addSorted xs s)
	| otherwise = s:x:xs

removeSorted :: (Ord a) => [a] -> a -> [a]
removeSorted [] _ = []
removeSorted (x:xs) s
	| (s == x) = xs
	| otherwise = x:(removeSorted xs s)

func :: [Integer] -> IO () 
func xs = do
	putStrLn "\n0 - exit \r1 - add value to sorted list \r2 - remove value from list \r3 - print list"
	symbol <- getLine   --troubles if getChar
	case symbol of 
		"0" -> return ()
		"1" -> do 
					putStr "Enter the value "
					num <- getLine
					func (addSorted xs (read num :: Integer))
		"2" -> do 
					putStr "Enter the value "
					num <- getLine
					func (removeSorted xs (read num :: Integer))
		"3" -> do 
					print (show xs)
					func xs
		otherwise -> func xs

main = func []