import Data.List
import Control.Monad
import Test.QuickCheck

combine :: Integer -> [a] -> [[a]]
combine 0 xs = [[]]
combine n xs = concat [map (x:) (combine (n-1) xs) | x <- xs]