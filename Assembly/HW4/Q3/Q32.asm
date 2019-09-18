.model  small
.stack   100h
.data
C db '  one  one  two   three  four  five   five    six$'
.code
	mov	ax,	@data
	mov	ds,	ax

.exit
end
