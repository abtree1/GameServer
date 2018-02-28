namespace NetIOCP {
	enum class IO_Operation : unsigned char {
		IO_Accept_Completed,
		IO_Disconnect_Completed,
		IO_Read_Completed,
		IO_Write_Completed,
		IO_Termination
	};
}