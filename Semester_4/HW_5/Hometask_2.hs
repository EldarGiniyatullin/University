import Data.List
import Control.Monad
import Test.QuickCheck

check :: (a -> Bool) -> [a] -> Bool
check _ [] = True
check f (x:xs) = if (f x) then (check f xs) else False