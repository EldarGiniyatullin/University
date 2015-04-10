import Data.List
import Control.Monad

multi :: Integer -> [Integer]
multi n = [1..n] >>= (\a -> (map (*a) [1..n]))