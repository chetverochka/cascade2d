#pragma once

namespace cascade {
	class Ref {
	public:
		Ref() : _referenceCount(0) {}
		void retain() { ++_referenceCount; }
		void release() {
			--_referenceCount;
			if (_referenceCount <= 0)	delete this;
		}
		int getReferenceCount() { return _referenceCount; }
	protected:
		virtual ~Ref() = default;
	private:
		int _referenceCount;
	};
}