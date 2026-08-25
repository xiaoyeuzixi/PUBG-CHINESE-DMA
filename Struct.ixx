export module Struct;
import std;
import FName;

static constexpr float PI = 3.14159265358979323846;


inline float DegreesToRadians(float Degrees) {
	return Degrees * PI / 180.0f;
}

export struct RectInfo {
	long x, y, w, h;
};

export struct FMeshBoneInfo
{
	FName Name_p;
	uint64_t Parent;
};




struct FQuat
{
    float                                         X;                                                            // 0x0000(0x0004)
    float                                         Y;                                                            // 0x0004(0x0004)
    float                                         Z;                                                            // 0x0008(0x0004)
    float                                         W;                                                            // 0x000C(0x0004)
};



export struct FVector2D
{
public:
	float X, Y;
public:
	constexpr FVector2D(float X = 0, float Y = 0) : X(X), Y(Y) {};

	constexpr FVector2D(const FVector2D& other) : X(other.X), Y(other.Y) {};


	FVector2D& Normalize()
	{
		*this /= Magnitude();

		return *this;
	}


	FVector2D& operator*=(float Scalar)
	{
		*this = *this * Scalar;

		return *this;
	}
	FVector2D& operator*=(const FVector2D& Other)
	{
		*this = *this * Other;

		return *this;
	}
	FVector2D& operator+=(const FVector2D& Other)
	{
		*this = *this + Other;

		return *this;
	}
	FVector2D& operator-=(const FVector2D& Other)
	{
		*this = *this - Other;

		return *this;
	}
	FVector2D& operator/=(float Scalar)
	{
		*this = *this / Scalar;

		return *this;
	}
	FVector2D& operator/=(const FVector2D& Other)
	{
		*this = *this / Other;

		return *this;
	}
	FVector2D& operator=(const FVector2D& other)
	{
		X = other.X;
		Y = other.Y;

		return *this;
	}

	float Dot(const FVector2D& Other) const
	{
		return (X * Other.X) + (Y * Other.Y);
	}
	float GetDistanceTo(const FVector2D& Other) const
	{
		FVector2D DiffVector = Other - *this;

		return DiffVector.Magnitude();
	}
	FVector2D GetNormalized() const
	{
		return *this / Magnitude();
	}
	bool IsZero() const
	{
		return X == 0 && Y == 0;
	}
	float Magnitude() const
	{
		return std::sqrt((X * X) + (Y * Y));
	}
	bool operator!=(const FVector2D& Other) const
	{
		return X != Other.X || Y != Other.Y;
	}
	FVector2D operator*(float Scalar) const
	{
		return { X * Scalar, Y * Scalar };
	}
	FVector2D operator*(const FVector2D& Other) const
	{
		return { X * Other.X, Y * Other.Y };
	}
	FVector2D operator+(const FVector2D& Other) const
	{
		return { X + Other.X, Y + Other.Y };
	}
	FVector2D operator-(const FVector2D& Other) const
	{
		return { X - Other.X, Y - Other.Y };
	}
	FVector2D operator/(float Scalar) const
	{
		if (Scalar == 0)
			return *this;

		return { X / Scalar, Y / Scalar };
	}
	FVector2D operator/(const FVector2D& Other) const
	{
		if (Other.X == 0 || Other.Y == 0)
			return *this;

		return { X / Other.X, Y / Other.Y };
	}
	bool operator==(const FVector2D& Other) const
	{
		return X == Other.X && Y == Other.Y;
	}
};


export struct FRotator
{
	float                                         Pitch;                                                        // 0x0000(0x0004)
	float                                         Yaw;                                                          // 0x0004(0x0004)
	float                                         Roll;                                                         // 0x0008(0x0004)
};

export struct FVector
{
	float X, Y, Z;
};

export struct FVector3D
{
public:

	float X, Y, Z;

public:



	constexpr FVector3D(float X = 0, float Y = 0, float Z = 0)
		: X(X), Y(Y), Z(Z)
	{
	}

	constexpr FVector3D(const FVector3D& other)
		: X(other.X), Y(other.Y), Z(other.Z)
	{
	}




	FVector3D& Normalize()
	{
		*this /= Magnitude();

		return *this;
	}

	FVector3D& operator*=(float Scalar)
	{
		*this = *this * Scalar;
		return *this;
	}


	FVector3D& operator*=(const FVector3D& Other)
	{
		*this = *this * Other;
		return *this;
	}

	FVector3D& operator+=(const FVector3D& Other)
	{
		*this = *this + Other;
		return *this;
	}

	FVector3D& operator-=(const FVector3D& Other)
	{
		*this = *this - Other;
		return *this;
	}

	FVector3D& operator/=(float Scalar)
	{
		*this = *this / Scalar;

		return *this;
	}
	FVector3D& operator/=(const FVector3D& Other)
	{
		*this = *this / Other;

		return *this;
	}

	FVector3D& operator=(const FVector3D& other)
	{
		X = other.X;
		Y = other.Y;
		Z = other.Z;

		return *this;
	}

	float Dot(const FVector3D& Other) const
	{
		return (X * Other.X) + (Y * Other.Y) + (Z * Other.Z);
	}

	float GetDistanceTo(const FVector3D& Other) const
	{
		FVector3D DiffVector = Other - *this;

		return DiffVector.Magnitude();
	}

	float GetDistanceToInMeters(const FVector3D& Other) const
	{
		return GetDistanceTo(Other) * static_cast<float>(0.01);
	}

	FVector3D GetNormalized() const
	{
		return *this / Magnitude();
	}

	bool IsZero() const
	{
		return X == 0 && Y == 0 && Z == 0;
	}


	float Magnitude() const
	{
		return std::sqrt((X * X) + (Y * Y) + (Z * Z));
	}




	bool operator!=(const FVector3D& Other) const
	{
		return X != Other.X || Y != Other.Y || Z != Other.Z;
	}

	FVector3D operator*(float Scalar) const
	{
		return { X * Scalar, Y * Scalar, Z * Scalar };
	}
	FVector3D operator*(const FVector3D& Other) const
	{
		return { X * Other.X, Y * Other.Y, Z * Other.Z };
	}
	FVector3D operator+(const FVector3D& Other) const
	{
		return { X + Other.X, Y + Other.Y, Z + Other.Z };
	}
	FVector3D operator-(const FVector3D& Other) const
	{
		return { X - Other.X, Y - Other.Y, Z - Other.Z };
	}
	FVector3D operator/(float Scalar) const
	{
		if (Scalar == 0)
			return *this;

		return { X / Scalar, Y / Scalar, Z / Scalar };
	}
	FVector3D operator/(const FVector3D& Other) const
	{
		if (Other.X == 0 || Other.Y == 0 || Other.Z == 0)
			return *this;

		return { X / Other.X, Y / Other.Y, Z / Other.Z };
	}
	bool operator==(const FVector3D& Other) const
	{
		return X == Other.X && Y == Other.Y && Z == Other.Z;
	}


	static void GetAxes(FRotator Rotation, FVector3D* X, FVector3D* Y, FVector3D* Z)
	{
		float radPitch = (Rotation.Pitch * PI / 180);
		float radYaw = (Rotation.Yaw * PI / 180);
		float radRoll = (Rotation.Roll * PI / 180);

		float SP = std::sin(radPitch);
		float CP = std::cos(radPitch);
		float SY = std::sin(radYaw);
		float CY = std::cos(radYaw);
		float SR = std::sin(radRoll);
		float CR = std::cos(radRoll);

		X->X = CP * CY;
		X->Y = CP * SY;
		X->Z = SP;

		Y->X = SR * SP * CY - CR * SY;
		Y->Y = SR * SP * SY + CR * CY;
		Y->Z = -SR * CP;

		Z->X = -(CR * SP * CY + SR * SY);
		Z->Y = CY * SR - CR * SP * SY;
		Z->Z = CR * CP;
	}

};



export struct FVector4D
{

	float X, Y, Z, W;
	FVector4D() = default;

	FVector4D(const float x, const float y, const float z, const float w)
		: X(x), Y(y), Z(z), W(w) {
	}

	FVector4D(const FVector3D& v3, const float W)
		: X(v3.X), Y(v3.Y), Z(v3.Z), W(W) {
	}


};


export struct FTransform
{
	FQuat                                         Rotation;                                                     // 0x0000(0x0010)
	FVector3D                                     Translation;                                                  // 0x0010(0x000C)
	char                                          pa_001C[0x0004];                                               // 0x001C(0x0004)
	FVector3D                                     Scale3D;                                                      // 0x0020(0x000C)
	char                                          pa_002C[0x0004];                                               // 0x002C(0x0004)
};

export struct FMatrix {
public:

	float M[4][4];

public:


	// 乘法运算符重载
	FMatrix operator*(const FMatrix& Other)
	{
		FMatrix Result;
		VectorMatrixMultiply1(&Result, this, &Other);
		return Result;
		//return VectorMatrixMultiply(this, &Other);

	}


	static void VectorMatrixMultiply1(FMatrix* Result, const FMatrix* Matrix1, const FMatrix* Matrix2)
	{
		typedef float M4x4[4][4];
		const M4x4& A = *((const M4x4*)Matrix1);
		const M4x4& B = *((const M4x4*)Matrix2);
		M4x4 Temp;
		Temp[0][0] = A[0][0] * B[0][0] + A[0][1] * B[1][0] + A[0][2] * B[2][0] + A[0][3] * B[3][0];
		Temp[0][1] = A[0][0] * B[0][1] + A[0][1] * B[1][1] + A[0][2] * B[2][1] + A[0][3] * B[3][1];
		Temp[0][2] = A[0][0] * B[0][2] + A[0][1] * B[1][2] + A[0][2] * B[2][2] + A[0][3] * B[3][2];
		Temp[0][3] = A[0][0] * B[0][3] + A[0][1] * B[1][3] + A[0][2] * B[2][3] + A[0][3] * B[3][3];

		Temp[1][0] = A[1][0] * B[0][0] + A[1][1] * B[1][0] + A[1][2] * B[2][0] + A[1][3] * B[3][0];
		Temp[1][1] = A[1][0] * B[0][1] + A[1][1] * B[1][1] + A[1][2] * B[2][1] + A[1][3] * B[3][1];
		Temp[1][2] = A[1][0] * B[0][2] + A[1][1] * B[1][2] + A[1][2] * B[2][2] + A[1][3] * B[3][2];
		Temp[1][3] = A[1][0] * B[0][3] + A[1][1] * B[1][3] + A[1][2] * B[2][3] + A[1][3] * B[3][3];

		Temp[2][0] = A[2][0] * B[0][0] + A[2][1] * B[1][0] + A[2][2] * B[2][0] + A[2][3] * B[3][0];
		Temp[2][1] = A[2][0] * B[0][1] + A[2][1] * B[1][1] + A[2][2] * B[2][1] + A[2][3] * B[3][1];
		Temp[2][2] = A[2][0] * B[0][2] + A[2][1] * B[1][2] + A[2][2] * B[2][2] + A[2][3] * B[3][2];
		Temp[2][3] = A[2][0] * B[0][3] + A[2][1] * B[1][3] + A[2][2] * B[2][3] + A[2][3] * B[3][3];

		Temp[3][0] = A[3][0] * B[0][0] + A[3][1] * B[1][0] + A[3][2] * B[2][0] + A[3][3] * B[3][0];
		Temp[3][1] = A[3][0] * B[0][1] + A[3][1] * B[1][1] + A[3][2] * B[2][1] + A[3][3] * B[3][1];
		Temp[3][2] = A[3][0] * B[0][2] + A[3][1] * B[1][2] + A[3][2] * B[2][2] + A[3][3] * B[3][2];
		Temp[3][3] = A[3][0] * B[0][3] + A[3][1] * B[1][3] + A[3][2] * B[2][3] + A[3][3] * B[3][3];
		std::memcpy(Result, &Temp, 16 * sizeof(float));
	}


	static FMatrix ToMatrixWithScale(const FTransform& Ft)
	{
		FMatrix OutMatrix{};

		OutMatrix.M[3][0] = Ft.Translation.X;
		OutMatrix.M[3][1] = Ft.Translation.Y;
		OutMatrix.M[3][2] = Ft.Translation.Z;

		const float x2 = Ft.Rotation.X + Ft.Rotation.X;
		const float y2 = Ft.Rotation.Y + Ft.Rotation.Y;
		const float z2 = Ft.Rotation.Z + Ft.Rotation.Z;
		{
			const float xx2 = Ft.Rotation.X * x2;
			const float yy2 = Ft.Rotation.Y * y2;
			const float zz2 = Ft.Rotation.Z * z2;

			OutMatrix.M[0][0] = (1.0 - (yy2 + zz2)) * Ft.Scale3D.X;
			OutMatrix.M[1][1] = (1.0 - (xx2 + zz2)) * Ft.Scale3D.Y;
			OutMatrix.M[2][2] = (1.0 - (xx2 + yy2)) * Ft.Scale3D.Z;
		}
		{
			const float yz2 = Ft.Rotation.Y * z2;
			const float wx2 = Ft.Rotation.W * x2;

			OutMatrix.M[2][1] = (yz2 - wx2) * Ft.Scale3D.Z;
			OutMatrix.M[1][2] = (yz2 + wx2) * Ft.Scale3D.Y;
		}
		{
			const float xy2 = Ft.Rotation.X * y2;
			const float wz2 = Ft.Rotation.W * z2;

			OutMatrix.M[1][0] = (xy2 - wz2) * Ft.Scale3D.Y;
			OutMatrix.M[0][1] = (xy2 + wz2) * Ft.Scale3D.X;
		}
		{
			const float xz2 = Ft.Rotation.X * z2;
			const float wy2 = Ft.Rotation.W * y2;

			OutMatrix.M[2][0] = (xz2 + wy2) * Ft.Scale3D.Z;
			OutMatrix.M[0][2] = (xz2 - wy2) * Ft.Scale3D.X;
		}

		OutMatrix.M[0][3] = 0.0;
		OutMatrix.M[1][3] = 0.0;
		OutMatrix.M[2][3] = 0.0;
		OutMatrix.M[3][3] = 1.0;

		return OutMatrix;
	};

	static FVector3D GetOrigin(FMatrix fm)
	{
		return { fm.M[3][0], fm.M[3][1], fm.M[3][2] };
	}
};

export struct FBoxSphereBounds
{
public:
	struct FVector3D                                Origin;
	struct FVector3D                                BoxExtent;
	float											SphereRadius;

public:

	std::array<FVector3D, 8> GetBoxCorners(const FTransform& FT) {
		auto ori = Origin + FT.Translation;
		std::array<FVector3D, 8> boxPoints = {
			FVector3D(ori.X - BoxExtent.X, ori.Y - BoxExtent.Y, ori.Z - BoxExtent.Z),
			FVector3D(ori.X + BoxExtent.X, ori.Y - BoxExtent.Y, ori.Z - BoxExtent.Z),
			FVector3D(ori.X + BoxExtent.X, ori.Y + BoxExtent.Y, ori.Z - BoxExtent.Z),
			FVector3D(ori.X - BoxExtent.X, ori.Y + BoxExtent.Y, ori.Z - BoxExtent.Z),
																
			FVector3D(ori.X - BoxExtent.X, ori.Y - BoxExtent.Y, ori.Z + BoxExtent.Z),
			FVector3D(ori.X + BoxExtent.X, ori.Y - BoxExtent.Y, ori.Z + BoxExtent.Z),
			FVector3D(ori.X + BoxExtent.X, ori.Y + BoxExtent.Y, ori.Z + BoxExtent.Z),
			FVector3D(ori.X - BoxExtent.X, ori.Y + BoxExtent.Y, ori.Z + BoxExtent.Z)
		};
		return boxPoints;
	}

	FVector3D GetTopCenter(const FTransform& FT) {

		auto ori = Origin + FT.Translation;
		return FVector3D(ori.X, ori.Y, ori.Z + BoxExtent.Z);

	}

	FVector3D GetBottomCenter(const FTransform& FT) {

		auto ori = Origin + FT.Translation;
		return FVector3D(ori.X, ori.Y, ori.Z - BoxExtent.Z);

	}
};



export struct FMinimalViewInfo
{
	FVector3D                                     Location;                                                     // 0x0000(0x000C)
	FVector3D                                     LocationLocalSpace;                                           // 0x000C(0x000C)
	FRotator                                      Rotation;                                                     // 0x0018(0x000C)
	char                                          pa_0004[0x0004];                                               // 0x0004(0x000C)
	FName                                         ViewTag;                                                      // 0x0028(0x0008)
	float                                         FOV;                                                          // 0x0030(0x0004)
};


export struct FCameraCacheEntry
{
public:

	float                                         TimeStamp;                                                    // 0x0000(0x0004)
	char                                          pa_0004[0x000C];                                               // 0x0004(0x000C)
	FMinimalViewInfo                              POV;                                                          // 0x0010(0x06A0)

public:
	FVector3D GetCameraForwardLocation(float Distance)
	{
		// 将旋转转换为弧度
		float PitchRad = DegreesToRadians(POV.Rotation.Pitch);
		float YawRad = DegreesToRadians(POV.Rotation.Yaw);

		// 计算前向向量
		FVector3D ForwardVector;
		ForwardVector.X = cos(PitchRad) * cos(YawRad);
		ForwardVector.Y = cos(PitchRad) * sin(YawRad);
		ForwardVector.Z = sin(PitchRad);

		// 计算前方距离处的坐标
		FVector3D TargetLocation;
		TargetLocation.X = POV.Location.X + ForwardVector.X * Distance;
		TargetLocation.Y = POV.Location.Y + ForwardVector.Y * Distance;
		TargetLocation.Z = POV.Location.Z + ForwardVector.Z * Distance;

		return TargetLocation;
	}


};