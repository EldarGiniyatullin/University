module Main where

--fibList :: (Integer a) => a -> [a]
fibList 0 = [0]
fibList 1 = [1, 0]
fibList x = [last] ++ readyFib where
	readyFib = fibList (x - 1)
	last = (readyFib !! 0) + (readyFib !! 1) 

fib x = (fibList x) !! 0 

main = print (fib 5)