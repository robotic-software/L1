class Person:
	def __init__(self, name, age, location):
		self.name = name
		self.age = age
		self.location = location


	def change_name( self, new_name ):
		self.name = new_name

	def change_location ( self, new_location ):
		self.location = new_location

	def print_location ( self ):
		print( self.location )



if __name__ == "__main__":
	p = Person( "Jonathan", 34, "Napoli")
	p.print_location()
	p.change_location( "Bologna" )
	print("New location: ")
	p.print_location()

