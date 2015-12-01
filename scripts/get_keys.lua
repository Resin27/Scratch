testvalue = 5
print 'Getting keys!'
function get_keys(t)
	local keys = {}
	if type(t) == "table" then
		local keys = {}
		for k,v in pairs(t) do
			table.insert(keys,k)
		end
		return keys
	end
	if type(t) == "number" then
		print 'Is a number!'
	end
	print 'Not a table!'
	return nil
end