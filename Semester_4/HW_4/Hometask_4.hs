import Data.Map (Map)
import qualified Data.Map as Map
import Test.HUnit

--The reason of using Data.Map instead of Data.Tree is lack of insert/member in second one

areDiff :: (Eq a, Ord a) => [a] -> Map a a -> Bool
areDiff [] _ = True
areDiff (x:xs) acc = if (Map.member x acc) then False else (areDiff xs (Map.insert x x acc))

areDifference :: (Eq a, Ord a) => [a] -> Bool
areDifference xs = areDiff xs Map.empty

assert1 = TestCase (assertEqual "testNotDiff" False (areDifference [3, 5, 1, 4, 8, 0, 4, 11]))
assert2 = TestCase (assertEqual "testDiff" True (areDifference [3, 5, 1, 4, 6, 8, 0, -5, 11, 17, 24, -44]))

tests = TestList [TestLabel "test1" assert1, TestLabel "test2" assert2]