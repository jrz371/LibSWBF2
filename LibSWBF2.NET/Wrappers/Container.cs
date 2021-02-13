﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;
using System.Threading; 

using LibSWBF2.Logging;
using LibSWBF2.Enums;
using LibSWBF2.Utils;


namespace LibSWBF2.Wrappers
{
    public class Container : NativeWrapper
    {
        private static Dictionary<Type, uint> wrapperMap;
        

        public Container() : base(APIWrapper.Container_Initialize()){}
        
        static Container()
        {
            wrapperMap = new Dictionary<Type, uint>();
            wrapperMap[typeof(Model)]        = 1;
            wrapperMap[typeof(Texture)]      = 2;
            wrapperMap[typeof(World)]        = 3;
            wrapperMap[typeof(EntityClass)]  = 4;
            wrapperMap[typeof(AnimationBank)] = 5;
        }


        ~Container()
        {
            Delete();
        }

        public void Delete()
        {
            if (IsValid())
            { 
                APIWrapper.Container_Delete(NativeInstance);
                Invalidate();
            }
        }


        public uint AddLevel(string path)
        {
            return APIWrapper.Container_AddLevel(NativeInstance, path);
        }

        public float GetProgress(uint handle)
        {
            return APIWrapper.Container_GetProgress(NativeInstance, handle);
        }

        public Level GetLevel(uint handle, bool block = false)
        {
            while (!IsDone())
            {
                if (block)
                {
                    Thread.Sleep(200);
                } 
                else 
                {
                    return null;
                } 
            }

            return Level.FromNative(APIWrapper.Container_GetLevel(NativeInstance, handle));
        }

        public void LoadLevels()
        {
            APIWrapper.Container_LoadLevels(NativeInstance);
        }

        public T FindWrapper<T>(string name) where T : NativeWrapper, new()
        {
            if (wrapperMap.ContainsKey(typeof(T)))
            {
                T newObj = new T();
                IntPtr ptr = APIWrapper.Container_GetWrapper(NativeInstance, wrapperMap[typeof(T)], name);

                if (ptr == null)
                {
                    return null;
                }

                newObj.SetPtr(ptr);

                return newObj;
            }

            return null;
        }


        public Config FindConfig(ConfigType type, uint nameHash=0)
        {
            IntPtr cfgPtr = APIWrapper.Container_GetConfig(NativeInstance, (uint) type, nameHash);
            if (cfgPtr == IntPtr.Zero)
            {
                return null;
            }

            return new Config(cfgPtr);
        }


        public Config FindConfig(ConfigType type, string name)
        {
            return FindConfig(type, HashUtils.GetFNV(name));
        }


        public bool IsDone()
        {
            return APIWrapper.Container_IsDone(NativeInstance);
        }
    }
}
