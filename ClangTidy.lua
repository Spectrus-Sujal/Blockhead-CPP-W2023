-- Enable a built-in check that detects unnecessary copies caused by
-- for range loops where the iterator is not by reference.
enable_checks("performance-for-range-copy")

-- Enable an Unreal Engine check where you incorrectly call Remove() 
-- on an array reference that still points into the array.
enable_checks("unreal-broken-array-call") 

-- Treat both of these as errors, not warnings.
treat_as_errors("performance-for-range-copy")
treat_as_errors("unreal-broken-array-call")

-- TIP: You can also use wildcards like "unreal-*" to enable all Unreal
--      Engine checks or treat all Unreal Engine checks as errors.