namespace bd_so {
	class BroadcastCenter {
		private:
		bool is_sender; /// is a caster;
		bool is_casting; /// is sending broadcast 
		bool is_receiving; /// is waiting broadcast
		public:
		BroadcastCenter(bool is_s):is_sender(is_s) {
		}		
		void startSend(void); 
		void startReceiving(void);	
	};
};
