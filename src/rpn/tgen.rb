init = Array.new(256)
subs = Array.new(256)

class Array
	def merge_key(c, opt)
		i = c[0]
		if(self[i])
			self[i] = "#{self[i]} | #{opt}"
		else
			self[i] = opt
		end
	end
end

['_', "'", '"'].each do |c|
	init.merge_key(c, 'IDENTIFIER')
	subs.merge_key(c, 'IDENTIFIER')
end

('A'..'Z').each do |c|
	init.merge_key(c, 'IDENTIFIER')
	subs.merge_key(c, 'IDENTIFIER')
end

('a'..'z').each do |c|
	init.merge_key(c, 'IDENTIFIER')
	subs.merge_key(c, 'IDENTIFIER')
end

('0'..'9').each do |c|
	init.merge_key(c, 'NUMBER')
	subs.merge_key(c, 'NUMBER')
	subs.merge_key(c, 'IDENTIFIER')
end

init.merge_key('.', 'NUMBER')
subs.merge_key('.', 'NUMBER')

['+', '-', '*', '/', '%', '~', '^', '!', ',', '@', '#', '$', '&', '|', '\\', ':', ';', '?'].each do |c|
	init.merge_key(c, 'OPERATOR')
end

['(', '[', '{', '}', ']', ')'].each do |c|
	init.merge_key(c, 'BRACKET')
end

[' ', "\t", "\r", "\n"].each do |c|
	init.merge_key(c, 'BLANK')
end

(0..255).each do |i|
	init[i] ||= '0'
	subs[i] ||= '0'
end

File.open('tokens.cpp', 'w') do |f|
	f << "#include \"parser.h\"\n\nnamespace RPN\n{"
	
	f << "\n\tconst unsigned char Parser::cInitial[256] = {\n\t\t"
	f << init.join(",\n\t\t")
	f << "\n\t};\n\t"
	
	f << "\n\tconst unsigned char Parser::cSubsequent[256] = {\n\t\t"
	f << subs.join(",\n\t\t")
	f << "\n\t};\n}\n"
end
