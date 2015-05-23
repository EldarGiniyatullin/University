import Control.Monad.Cont

map_cs :: (a -> b) -> [a] -> Cont r [b]
map_cs _ [] = return []
map_cs f (x:xs) = (map_cs f xs) >>= (\ms -> return ((f x):ms))

filter_cs :: (a -> Bool) -> [a] -> Cont r [a]
filter_cs _ [] = return []
filter_cs f (x:xs) = (filter_cs f xs) >>= (\ms -> return $ (if (f x) then (x:) else id) $ ms)

main = runCont (runCont (filter_cs (>0) [-2, -3, 5, -1, 4]) (map_cs ((*) 2))) print