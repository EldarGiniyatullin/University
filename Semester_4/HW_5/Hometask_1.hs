import Data.List
import Control.Monad
import Test.QuickCheck



forFunc :: [a] -> (a -> b) -> [b]
forFunc [] _ = []
forFunc (x:xs) f = (f x):(forFunc xs f)


sums :: Integer -> [Integer] -> Integer -> [[Integer]]
sums 0 curr _ = [curr]
sums num curr prev = concat [sums (num - x) (x:curr) x | x <- [1..(min num prev)]]

printList :: (Show a) => [a] -> IO ()
printList [] = return ()
printList [x] = putStrLn (show x)
printList (x:xs) = do 
						putStr ((show x) ++ " + ")
						printList xs

sumsPrint :: Integer -> IO [()]
sumsPrint num = forM (sums num [] num) (\x -> putStr ((show num) ++ " = ") >>  printList x)