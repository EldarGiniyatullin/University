import Data.Maybe
import Control.Monad
import Test.HUnit

operWith3 :: (Ord a) => [a] -> (a -> a-> a -> Bool) -> Maybe a
operWith3 [] _ = fail ""
operWith3 [a] _ = fail ""
operWith3 [a, b] _ = fail ""
operWith3 (a:b:c:xs) f = if (f a b c) then (return b) else operWith3 (b:c:xs) f

midMax3 :: (Ord a) => a -> a -> a -> Bool
midMax3 a b c = (b > max a c)

grossNeighbour :: (Ord a) => [a] -> Maybe a
grossNeighbour xs = operWith3 xs midMax3 

assert1 = TestCase (assertEqual "5" 				 (Just 5) (grossNeighbour [1, -3, 1, 5, 4, 3, 1]))
assert2 = TestCase (assertEqual "5, not 7" 		   	 (Just 5) (grossNeighbour [1, -3, 1, 5, 4, 3, 7, 1]))
assert3 = TestCase (assertEqual "Greatest in the end" Nothing (grossNeighbour [1, -3, 1, 3, 4, 9, 12, 14]))

tests = TestList [TestLabel "5" assert1, TestLabel "5, not 7" assert1, TestLabel "Greatest in the end" assert3]

main = runTestTT tests